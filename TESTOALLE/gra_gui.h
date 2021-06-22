#pragma once
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>
void gra_gui0(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* lvl1);
void gra_gui1(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l1, bool zamek_bool, ALLEGRO_BITMAP* zamek_img, int* zamek_kod);
void gra_gui2(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l2, bool obraz_tv, ALLEGRO_BITMAP* tv_img);
void gra_gui3(int zegar, int lvl, bool piwnica, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l3, ALLEGRO_BITMAP* k1, ALLEGRO_BITMAP* k2, ALLEGRO_BITMAP* k3, ALLEGRO_BITMAP* k4, bool azorek_bool, bool czibo_bool, bool korek_bool, bool rybka_bool);
void gra_gui4(int zegar, int lvl, ALLEGRO_BITMAP* l4);
void gra_gui5(int zegar, int lvl, ALLEGRO_BITMAP* l5, ALLEGRO_BITMAP* l5a, bool rakieta, ALLEGRO_BITMAP* r_tlo, ALLEGRO_BITMAP* tlo2, ALLEGRO_BITMAP* r_tv, ALLEGRO_BITMAP* rakieta_img, int x);
void gra_gui7(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* pustynia);
void gra_gui12(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l12);
void gra_gui12a(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l12);
void gra_gui14(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l14);
void gra_gui17(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l17, ALLEGRO_BITMAP* l18);
void gra_gui19(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l19);
void gra_gui20(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l20, ALLEGRO_BITMAP* l21, int *tv_kod);
void gra_gui23(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l19, ALLEGRO_BITMAP* l24);
void gra_gui25(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l20);