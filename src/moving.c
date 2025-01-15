#include "../minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/time.h> // Pour gettimeofday

typedef struct s_data {
    void    *mlx;        // Pointeur pour MinilibX
    void    *win;        // Fenêtre
    void    *img;        // Image
    int     img_width;   // Largeur de l'image
    int     img_height;  // Hauteur de l'image
    float   x;           // Position X de l'image
    float   y;           // Position Y de l'image
    int     move_x;      // Direction X (1 = droite, -1 = gauche, 0 = pas de mouvement)
    int     move_y;      // Direction Y (1 = bas, -1 = haut, 0 = pas de mouvement)
    float   speed;       // Vitesse de déplacement (pixels par seconde)
    struct timeval last_time; // Dernier temps enregistré
}   t_data;

// Fonction pour initialiser le temps actuel
void init_time(t_data *data)
{
    gettimeofday(&data->last_time, NULL);
}

// Fonction pour calculer le temps écoulé (en secondes)
float get_elapsed_time(t_data *data)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    float elapsed = (current_time.tv_sec - data->last_time.tv_sec) +
                    (current_time.tv_usec - data->last_time.tv_usec) / 1000000.0;

    data->last_time = current_time; // Mettre à jour le dernier temps
    return elapsed;
}

// Fonction appelée lorsqu'une touche est pressée
int handle_keypress(int keycode, t_data *data)
{
    if (keycode == 65307) // Touche ESC (quitter)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    else if (keycode == 119) // Touche W
        data->move_y = -1; // Déplacement vers le haut
    else if (keycode == 115) // Touche S
        data->move_y = 1; // Déplacement vers le bas
    else if (keycode == 97)  // Touche A
        data->move_x = -1; // Déplacement vers la gauche
    else if (keycode == 100) // Touche D
        data->move_x = 1; // Déplacement vers la droite

    return (0);
}

// Fonction appelée lorsqu'une touche est relâchée
int handle_keyrelease(int keycode, t_data *data)
{
    if (keycode == 119 || keycode == 115) // Touche W ou S
        data->move_y = 0; // Arrêter le mouvement vertical
    else if (keycode == 97 || keycode == 100) // Touche A ou D
        data->move_x = 0; // Arrêter le mouvement horizontal

    return (0);
}

// Fonction appelée à chaque itération de la boucle principale
int render_next_frame(t_data *data)
{
    float elapsed_time = get_elapsed_time(data); // Temps écoulé depuis la dernière frame

    // Mise à jour des positions X et Y
    data->x += data->move_x * data->speed * elapsed_time;
    data->y += data->move_y * data->speed * elapsed_time;

    // Limiter l'image aux bords de la fenêtre (800x600)
    if (data->x < 0)
        data->x = 0;
    if (data->x > 800 - data->img_width)
        data->x = 800 - data->img_width;
    if (data->y < 0)
        data->y = 0;
    if (data->y > 600 - data->img_height)
        data->y = 600 - data->img_height;

    // Effacer la fenêtre et redessiner l'image
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->img, (int)data->x, (int)data->y);

    return (0);
}

int main()
{
    t_data data;

    // Initialisation de MinilibX
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "Animation fluide avec MinilibX");

    // Charger l'image XPM
    data.img = mlx_xpm_file_to_image(data.mlx, "azfal.xpm", &data.img_width, &data.img_height);
    if (!data.img) // Vérifie si le chargement de l'image a échoué
    {
        write(2, "Erreur : Impossible de charger l'image XPM\n", 43);
        return (1);
    }

    // Position initiale de l'image
    data.x = 400; // Centre horizontal
    data.y = 300; // Centre vertical

    // Initialiser les variables de déplacement
    data.move_x = 0;
    data.move_y = 0;
    data.speed = 200; // Vitesse : 200 pixels par seconde

    // Initialiser le temps
    init_time(&data);

    // Attacher les événements
    mlx_hook(data.win, 2, 1L << 0, handle_keypress, &data);     // Appui sur une touche
    mlx_hook(data.win, 3, 1L << 1, handle_keyrelease, &data);  // Relâchement d'une touche
    mlx_loop_hook(data.mlx, render_next_frame, &data);         // Boucle d'animation

    // Lancer la boucle
    mlx_loop(data.mlx);

    return (0);
}
