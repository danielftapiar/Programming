#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>
#include <string.h>


struct actor{
     void (*show_attributes) (void *);
     void (*set_data) (void *);
     char name[20];
     char type;
     void *actor; //puntero a player, enemy o item
};

struct enemy{
     char type_enemy;
     int melee_atk;
     int ranged_atk;
};
struct item{
     char type_item;
     void *weapon_item; //puntero a weapon o null
};
struct weapon{
     int damage;
     int range;
     int burst; 
};

struct player{
     int life;
     struct weapon *equipped_weapon;
     int ammo;
};

int main(int argc, char const *argv[])
{
     FILE *mapaFile = fopen("mapa.txt", "r");
     

     if (mapaFile == NULL)
     {
          printf("File didn't open properly\n");
     }
     
     return(0);
}