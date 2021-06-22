#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>


void gra_gui0(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* lvl1) {


	if (lvl == 0) {
		

		al_draw_scaled_bitmap(lvl1, 0, 0, 1580, 832, 0, 0, 1600, 900, 0);
		al_draw_filled_rounded_rectangle(30, 170, 1100, 400, 20, 20, al_map_rgba(0, 0, 0, 100));
		//TXT
		al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
		/*/EQ
		al_draw_filled_rounded_rectangle(100, 550, 1550, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_text(font36, al_map_rgb(220, 220, 220), 1350, 560, 0, "Plecak");
		*/
		
	}

	
}

void gra_gui1(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l1, bool zamek_bool, ALLEGRO_BITMAP* zamek_img, int* zamek_kod) {
	if (lvl == 1) {


		al_draw_bitmap(l1, 0, 0, 0);

		//TXT
		al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));

	}

	if (zamek_bool) {
		al_draw_bitmap(zamek_img, 500, 50, 0);
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 620, 162, 0, "%d %d %d %d", zamek_kod[1], zamek_kod[2], zamek_kod[3], zamek_kod[4]);
	}

}

void gra_gui2(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l2, bool obraz_tv, ALLEGRO_BITMAP* tv_img) {
	if (lvl == 2) {
		if (zegar >= 250) {
			al_draw_bitmap_region(l2, 0, 2, 1670, 970, 0, 0, NULL);
		}
		else {
			al_draw_bitmap_region(l2, 0, 969, 1670, 970, 0, 0, NULL);
		}

		//TXT
		al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));

		if (obraz_tv) {
			if (zegar <= 120) {
				al_draw_bitmap_region(tv_img, 0, 0, 600, 1800, 700, 0, NULL);
			}
			if (zegar <= 450 && zegar >= 120) {
				al_draw_bitmap_region(tv_img, 0, 1200, 600, 1800, 700, 0, NULL);
			}
		}
	}
}

void gra_gui3(int zegar, int lvl, bool piwnica, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l3, ALLEGRO_BITMAP* k1, ALLEGRO_BITMAP* k2, ALLEGRO_BITMAP* k3, ALLEGRO_BITMAP* k4, bool azorek_bool, bool czibo_bool, bool korek_bool, bool rybka_bool) {
	if (lvl == 3) {
		al_draw_bitmap(l3, 0, 0, 0);

		//TXT
		al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
	}
	if (azorek_bool) {
		al_draw_bitmap(k3, 260, 210, 0);
	}

	if (czibo_bool) {
		al_draw_bitmap(k4, 960, 35, 0);
	}

	if (korek_bool) {
		al_draw_bitmap(k2, 900, 271, 0);
	}
	if (rybka_bool) {
		al_draw_bitmap(k1, 670, 120, 0);
	}

}

void gra_gui4(int zegar, int lvl, ALLEGRO_BITMAP* l4) {
	if (lvl == 4) {
		al_draw_bitmap(l4, 0, 0, 0);
	}
}

void gra_gui5(int zegar, int lvl, ALLEGRO_BITMAP* l5, ALLEGRO_BITMAP* l5a, bool rakieta, ALLEGRO_BITMAP* r_tlo, ALLEGRO_BITMAP* tlo2, ALLEGRO_BITMAP* r_tv, ALLEGRO_BITMAP* rakieta_img, int x) {
	if (rakieta) {
		al_draw_bitmap(r_tlo, 0, 0, 0);
		if (zegar >= 250) {
			al_draw_bitmap_region(tlo2, 0, 0, 1600, 970, 0, 0, NULL);
		}
		else {
			al_draw_bitmap_region(tlo2, 0, 970, 1600, 970, 0, 0, NULL);
		}
		float w = al_get_bitmap_width(rakieta_img);
		float h = al_get_bitmap_height(rakieta_img);
		al_draw_rotated_bitmap(rakieta_img,w/2,h/2,1200,300,x,0);
		//TXT
		al_draw_filled_rounded_rectangle(100, 550, 710, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_filled_rounded_rectangle(120, 570, 690, 830, 20, 20, al_map_rgba(245, 245, 220, 100));

		al_draw_bitmap(r_tv, 0, 0, 0);
	}
	else {
		if (lvl == 5) {
			al_draw_bitmap(l5a, 0, 0, 0);
			if (zegar >= 250) {
				al_draw_bitmap_region(l5, 0, 0, 1670, 970, 0, 0, NULL);
			}
			if (zegar <= 120) {
				al_draw_bitmap_region(l5, 0, 970, 1670, 970, 0, 0, NULL);
			}
			if (zegar <= 250 && zegar >= 120) {
				al_draw_bitmap_region(l5, 0, 1940, 1670, 970, 0, 0, NULL);
			}
			//TXT
			al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
			al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
		}
	}
}

void gra_gui7(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* pustynia) {
	if (lvl == 7) {
		al_draw_bitmap_region(pustynia, 0, 0, 1600, 970, 0, 0, NULL);
		//TXT
		al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
	}
	if (lvl == 8) {
		al_draw_bitmap_region(pustynia, 0, 970, 1600, 970, 0, 0, NULL);
		//TXT
		al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
	}
	if (lvl == 9) {
		al_draw_bitmap_region(pustynia, 0, 1940, 1600, 970, 0, 0, NULL);
		//TXT
		al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
	}
	if (lvl == 10) {
		al_draw_bitmap_region(pustynia, 0, 2910, 1600, 970, 0, 0, NULL);
		//TXT
		al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
		
	}
	if (lvl == 11) {
		al_draw_bitmap_region(pustynia, 0, 3880, 1600, 970, 0, 0, NULL);
	}
}
void gra_gui12(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l12) {
	al_draw_bitmap(l12 , 0, 0, 0);
	//TXT
	al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
	al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
}
void gra_gui12a(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l12) {
	al_draw_bitmap_region(l12, 0, 900, 1600, 900, 0, 0, NULL);
	//TXT
	al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
	al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
}
void gra_gui14(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l14) {
	if (lvl == 14) {
		al_draw_bitmap_region(l14, 0, 0, 1600, 2700, 0, 0, NULL);
	}
	if (lvl == 15) {
		al_draw_bitmap_region(l14, 0, 900, 1600, 2700, 0, 0, NULL);

	}
	if (lvl == 16) {
		al_draw_bitmap_region(l14, 0, 1800, 1600, 2700, 0, 0, NULL);

	}
	al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
	al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
}
void gra_gui17(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l17, ALLEGRO_BITMAP* l18) {
	if (lvl == 17) {
		al_draw_bitmap(l17, 0, 0, 0);
	}
	if (lvl == 18) {
		al_draw_bitmap(l18, 0, 0, 0);
	}
	al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
	al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
}

void gra_gui19(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l19) {
	if (lvl == 19 || lvl == 22) {
		al_draw_bitmap(l19, 0, 0, 0);

		al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
	}
}

void gra_gui20(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l20, ALLEGRO_BITMAP* l21, int *tv_kod) {
	if (lvl == 20) {
		al_draw_bitmap(l20, 0, 0, 0);

		al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
	}
	if (lvl == 21) {
		al_draw_bitmap(l21, 0, 0, 0);
		al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 250, 300, 0, "%d %d %d %d %d", tv_kod[1], tv_kod[2], tv_kod[3], tv_kod[4], tv_kod[5]);
	}
}
void gra_gui23(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l18, ALLEGRO_BITMAP* l23) {
	if (lvl == 23) {
		al_draw_bitmap(l23, 0, 0, 0);

		al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
	}
	if (lvl == 24) {
		al_draw_bitmap(l18, 0, 0, 0);

		al_draw_filled_rounded_rectangle(100, 550, 1300, 850, 20, 20, al_map_rgba(0, 0, 0, 100));
		al_draw_filled_rounded_rectangle(120, 570, 1280, 830, 20, 20, al_map_rgba(245, 245, 220, 100));
	}
}
void gra_gui25(int zegar, int lvl, ALLEGRO_FONT* font36, ALLEGRO_BITMAP* l20) {
	al_draw_bitmap(l20, 0, 0, 0);

}