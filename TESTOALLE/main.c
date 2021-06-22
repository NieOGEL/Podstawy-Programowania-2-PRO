#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include "lvl.h"
#include "gra_gui.h"
void zero_tab(int* zamek_kod, int* tv_kod, int* kod_lvl3) {
	for (int i = 0; i <= 5; i++) {
		zamek_kod[i] = 0;
		tv_kod[i] = 0;
		kod_lvl3[i] = 0;
	}
}

int los() {
	int i = 0;
	i = (rand() % (100 - -100)) - 100;
	if (i == 0) {
		los();
	}
	else {
		return i;
	}
}

int main() {
	srand(time(NULL));
	
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	

	setlocale(LC_CTYPE, "Polish");

	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(2);
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_DISPLAY* display = NULL;

	ALLEGRO_FONT* font16 = al_load_font("./pliki/arial_e.ttf", 16, 0);
	ALLEGRO_FONT* font24 = al_load_font("./pliki/arial_e.ttf", 24, 0);
	ALLEGRO_FONT* font36 = al_load_font("./pliki/arial_e.ttf", 36, 0);
	ALLEGRO_FONT* font42 = al_load_font("./pliki/arial_e.ttf", 42, 0);
	ALLEGRO_FONT* font56 = al_load_font("./pliki/arial_e.ttf", 56, 0);

	ALLEGRO_SAMPLE* muzyka = NULL;
	ALLEGRO_SAMPLE_INSTANCE* testmuzyka = NULL;
	ALLEGRO_SAMPLE* zamek_klik = NULL;
	ALLEGRO_SAMPLE* open = NULL;
	ALLEGRO_SAMPLE* obrazek_ruch = NULL;
	ALLEGRO_SAMPLE* rakieta_klik = NULL;
	ALLEGRO_SAMPLE* kod_bunkier_ok = NULL;
	ALLEGRO_SAMPLE* sterownia = NULL;
	ALLEGRO_SAMPLE* pustynia = NULL;
	ALLEGRO_SAMPLE* tlo_domek = NULL;

	muzyka = al_load_sample("./pliki/muzyka/33_-_Pinch_Daisuki.mp3");
	zamek_klik = al_load_sample("./pliki/muzyka/zapsplat_multimedia_button_click_005_53866.mp3");
	obrazek_ruch = al_load_sample("./pliki/muzyka/zapsplat_technology_vr_headset_phone_tray_holder_slide_in_19161.mp3");
	rakieta_klik = al_load_sample("./pliki/muzyka/zapsplat_technology_video_game_nintendo_wii_console_electronic_click_002_66802.mp3");
	kod_bunkier_ok = al_load_sample("./pliki/muzyka/zapsplat_technology_pager_beep_003_40364.mp3");
	
	float volume = 0.1;
	float vol = 0.0;
	float volume_v = volume * 100;

	testmuzyka = al_create_sample_instance(muzyka);
	al_attach_sample_instance_to_mixer(testmuzyka, al_get_default_mixer());
	al_set_sample_instance_playmode(testmuzyka, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_gain(testmuzyka, volume);
	al_play_sample_instance(testmuzyka);
	

	int szer = 1600, wys = 900;
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	display = al_create_display(szer, wys);
	ALLEGRO_BITMAP* ikonka = al_load_bitmap("./pliki/Zdjecia/pp2.bmp");
	ALLEGRO_BITMAP* menu_img = al_load_bitmap("./pliki/Zdjecia/menu.png");
	ALLEGRO_BITMAP* lvl1 = NULL;
	ALLEGRO_BITMAP* l1 = NULL;
	ALLEGRO_BITMAP* l2 = NULL;
	ALLEGRO_BITMAP* l3 = NULL;
	ALLEGRO_BITMAP* zamek_img = NULL;
	ALLEGRO_BITMAP* tv_img = NULL;
	ALLEGRO_BITMAP* kor1_img = NULL;
	ALLEGRO_BITMAP* kor2_img = NULL;
	ALLEGRO_BITMAP* kor3_img = NULL;
	ALLEGRO_BITMAP* kor4_img = NULL;
	ALLEGRO_BITMAP* l4 = NULL;
	ALLEGRO_BITMAP* l5 = NULL;
	ALLEGRO_BITMAP* l5a = NULL;
	ALLEGRO_BITMAP* r_tlo = NULL;
	ALLEGRO_BITMAP* r_tlo2 = NULL;
	ALLEGRO_BITMAP* r_tv = NULL;
	ALLEGRO_BITMAP* rakieta_img = NULL;
	ALLEGRO_BITMAP* astro = NULL;
	ALLEGRO_BITMAP* pustynia_img = NULL;
	ALLEGRO_BITMAP* czacha = NULL;
	ALLEGRO_BITMAP* l12 = NULL;
	ALLEGRO_BITMAP* l14 = NULL;
	ALLEGRO_BITMAP* l17 = NULL;
	ALLEGRO_BITMAP* l18 = NULL;
	ALLEGRO_BITMAP* l19 = NULL;
	ALLEGRO_BITMAP* kop = NULL;
	ALLEGRO_BITMAP* l20 = NULL;
	ALLEGRO_BITMAP* l21 = NULL;
	ALLEGRO_BITMAP* znak_pyt = NULL;
	ALLEGRO_BITMAP* l23 = NULL;
	ALLEGRO_BITMAP* bunkier = NULL;


	int strzalka = 0;
	int mysz = -1;
	int wybor = 0;
	int wyk = 0;
	int level = 0;
	bool menu = true;
	bool mute = false;
	bool gra = false;
	bool exit = false;
	bool s_wyb = true;
	int strzalka_opcje = 0;
	int wyb_opcji = 0;
	int x=0, y=0;
	bool zamek_bool = false;
	bool obraz_tv = false;
	bool piwnica_bool = false;
	bool rybka_bool = true;
	bool korek_bool = true;
	bool czibo_bool = true;
	bool azorek_bool = true;
	bool rakieta = false;
	int rot_rak = los();
	int kod_lvl3[10];
	int ikod_lvl3 = 0;
	int wybor_level3 = 0;
	int level3_podejscia = 0;
	int zeg1 = 0; 
	int zeg2 = 0;
	int zamek_kod[10];
	int i_kod = 0;
	int tv_kod[10];
	int itv_kod = 0;
	bool tlo_muzyka = false;

	zero_tab(zamek_kod, tv_kod, kod_lvl3); // zerowanie tablic

	al_set_window_title(display, "Projekt PP2 - Pustynia");
	ALLEGRO_KEYBOARD_STATE key_state;
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);
	al_set_display_icon(display, ikonka);
	
	while (!exit)
	{
		ALLEGRO_EVENT ev;
		al_get_keyboard_state(&key_state);
		//al_get_next_event(event_queue, &ev);
		al_wait_for_event(event_queue, &ev);
		//al_clear_to_color(al_map_rgb(80, 0, 80))
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			exit = true;
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
			x = ev.mouse.x;
			y = ev.mouse.y;
		}
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			
			zeg1 = al_get_timer_count(timer);
			if (zeg1 >= 450) {
				al_set_timer_count(timer, 0);
			}
			
		}

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				if (level == 4) {
					al_destroy_bitmap(l4);
				}
				if (level == 6 || level == 23) {
					al_destroy_bitmap(rakieta_img);
				}
				if (level == 11) {
					al_destroy_bitmap(pustynia_img);
					al_destroy_bitmap(czacha);
					al_destroy_sample(pustynia);
					tlo_muzyka = false;
				}
				if (level == 19) {
					al_destroy_bitmap(l19);
					al_destroy_bitmap(l23);
					al_destroy_bitmap(znak_pyt);
					al_destroy_bitmap(kop);
				}
				if (level == 24) {
					al_destroy_bitmap(bunkier);
					al_destroy_bitmap(l19);
					al_destroy_bitmap(l23);
				}
				if (level == 22) {
					al_destroy_bitmap(l19);
					al_destroy_bitmap(l23);
					al_destroy_bitmap(kop);
					al_destroy_bitmap(znak_pyt);
				}
				if (level == 23) {
					al_destroy_bitmap(l19);
					al_destroy_bitmap(l23);
				}
				if (level == 25) {
					al_destroy_bitmap(l20);
					al_destroy_bitmap(czacha);
				}
				if (level == 4 || level == 6 || level == 11 || level == 19 || level == 22 || level == 23 || level == 24 || level == 25) {
					zero_tab(zamek_kod, tv_kod, kod_lvl3);
					rot_rak = los();
					strzalka = 0;
					mysz = -1;
					wybor = 0;
					wyk = 0;
					level = 0;
					menu = true;
					gra = false;
					exit = false;
					s_wyb = true;
					strzalka_opcje = 0;
					wyb_opcji = 0;
					x = 0, y = 0;
					zamek_bool = false;
					obraz_tv = false;
					piwnica_bool = false;
					rybka_bool = true;
					korek_bool = true;
					czibo_bool = true;
					azorek_bool = true;
					rakieta = false;
					ikod_lvl3 = 0;
					wybor_level3 = 0;
					level3_podejscia = 0;
					zeg1 = 0;
					zeg2 = 0;
					i_kod = 0;
					itv_kod = 0;
					tlo_muzyka = false;
				}
				
				menu = true;
				gra = false;
			}
		}


		if (!gra && !menu) {
			al_clear_to_color(al_map_rgb(56, 56, 56));

			if (x >= 70 && y >= 200 && x <= 400 && y <= 249) {
				strzalka_opcje = 0;

			}
			if (x >= 70 && y >= 250 && x <= 400 && y <= 299) {
				strzalka_opcje = 1;
			}
			if (x >= 70 && y >= 300 && x <= 400 && y <= 349) {
				strzalka_opcje = 2;
			}


			if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				if (ev.mouse.pressure) {

					if (ev.mouse.button & 2) {
						if (strzalka_opcje == 1 && !gra && !menu && x >= 70 && y >= 250 && x <= 500 && y <= 300) {
							if (volume <= 0.01) {
							}
							else {
								volume -= 0.01;
								volume_v = volume * 100;
								al_set_sample_instance_gain(testmuzyka, volume);
							}
						}
					}

					if (ev.mouse.button & 1) { //lewy

						if (strzalka_opcje == 0 && !gra && !menu && x >= 70 && y >= 200 && x <= 500 && y <= 250) {
							menu = true;
							gra = false;
						}
						if (strzalka_opcje == 1 && !gra && !menu && x >= 70 && y >= 250 && x <= 500 && y <= 300) {

							if (volume >= 1.49) {
							}
							else {
								volume += 0.01;
								volume_v = volume * 100;
								al_set_sample_instance_gain(testmuzyka, volume);
							}
						}
						
					}

				}

			}
		

			//==== 


				switch (strzalka_opcje)
				{
				case -1:
					al_draw_filled_rounded_rectangle(50, 200, 400, 250, 20, 20, al_map_rgba(224, 217, 177, 50));
					break;
				case 0:
					al_draw_filled_rounded_rectangle(50, 200, 400, 250, 20, 20, al_map_rgba(224, 217, 177, 50));
					break;
				case 1:
					al_draw_filled_rounded_rectangle(50, 250, 400, 300, 20, 20, al_map_rgba(224, 217, 177, 50));
					break;
				}

			al_draw_text(font42, al_map_rgb(49, 163, 49), 70, 100, 0, "Menu Opcje:");

			al_draw_text(font36, al_map_rgb(49, 163, 49), 70, 200, 0, "WrV@ do Menu");

			al_draw_textf(font36, al_map_rgb(49, 163, 49), 70, 250, 0, "G[oYnoY@: %.0f{", volume_v);
			al_draw_text(font36, al_map_rgb(0, 230, 54), 30, 800, 0, "PowrVt: ESCAPE");
			al_draw_text(font36, al_map_rgb(0, 230, 54), 30, 850, 0, "Zmiana G[oYnoYci <LPM g[oYniej / PPM ciszej>'");

		}



		if (gra && !menu) {
			if (level == 25) {
				gra_gui25(zeg1, level, font56, l20);
				lvl23(font56, level, x, y, czacha);
				wyb_opcji = -1;
				
			}
			if (level == 24) {
				wyb_opcji = -1;
				gra_gui23(zeg1, level, font36, l19, l23);
				lvl23(font36, level, x, y, bunkier);
			}

			if (level == 23) {
				wyb_opcji = -1;
				gra_gui23(zeg1, level, font36, l19 ,l23);
				lvl23(font36, level, x, y, rakieta_img);
			}

			if (level == 22) {
				wyb_opcji = -1;
				gra_gui19(zeg1, level, font36, l19, l23);
				lvl19(font36, level, x, y,kop, znak_pyt);
			}

			if (level == 21) {
				wyb_opcji = -1;
				gra_gui20(zeg1, level, font56, l20, l21, tv_kod);
				lvl20(font36, level, x, y);
				
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.pressure) {
						if (itv_kod <= 5) {
							if (x >= 223 && y >= 430 && x <= 300 && y <= 490) {
								al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								itv_kod++;
								tv_kod[itv_kod] = 1;

							}
							if (x >= 297 && y >= 430 && x <= 392 && y <= 490) {
								al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								itv_kod++;
								tv_kod[itv_kod] = 2;

							}
							if (x >= 396 && y >= 430 && x <= 496 && y <= 490) {
								al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								itv_kod++;
								tv_kod[itv_kod] = 3;

							}
							if (x >= 509 && y >= 430 && x <= 600 && y <= 490) {
								al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								itv_kod++;
								tv_kod[itv_kod] = 4;

							}
							if (x >= 610 && y >= 430 && x <= 710 && y <= 490) {
								al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								itv_kod++;
								tv_kod[itv_kod] = 5;

							}
							if (x >= 720 && y >= 430 && x <= 810 && y <= 490) {
								al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								itv_kod++;
								tv_kod[itv_kod] = 6;

							}
							if (x >= 825 && y >= 430 && x <= 930 && y <= 490) {
								al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								itv_kod++;
								tv_kod[itv_kod] = 7;

							}
							if (x >= 930 && y >= 430 && x <= 1030 && y <= 490) {
								al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								itv_kod++;
								tv_kod[itv_kod] = 8;

							}
							if (x >= 1040 && y >= 430 && x <= 1110 && y <= 490) {
								al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								itv_kod++;
								tv_kod[itv_kod] = 9;

							}
							if (x >= 1115 && y >= 430 && x <= 1200 && y <= 490) {
								al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								itv_kod++;
								tv_kod[itv_kod] = -1;

							}
						}
						if (x >= 1270 && y >= 490 && x <= 1430 && y <= 550) {
							al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

							if (tv_kod[1] == 1 && tv_kod[2] == 2 && tv_kod[3] == 3 && tv_kod[4] == 4 && tv_kod[5] == 0) {
								bunkier = al_load_bitmap("./pliki/Zdjecia/bunkier.png");
								l19 = al_load_bitmap("./pliki/Zdjecia/l19.png");
								l23 = al_load_bitmap("./pliki/Zdjecia/l23.png");
								level = 24;
							}
							else {
								l20 = al_load_bitmap("./pliki/Zdjecia/l20.png");
							    czacha = al_load_bitmap("./pliki/Zdjecia/czacha.png");
								level = 25;
							}
						}

					}
				}
				if (tv_kod[1] == 1 && tv_kod[2] == 2 && tv_kod[3] == 3 && tv_kod[4] == 4 && tv_kod[5] == -1) {
					tv_kod[5] = 0;
					al_play_sample(kod_bunkier_ok, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);	
				}
			}

			if (level == 20) {
				wyb_opcji = -1;
				gra_gui20(zeg1, level, font36, l20, l21,tv_kod);
				lvl20(font36, level, x, y);
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.pressure) {
						if (x >= 1050 && y >= 260 && x <= 1236 && y <= 415) {
							level = 21;
						}
						else if (x >= 1320 && y >= 0 && x <= 1600 && y <= 900) {
							l19 = al_load_bitmap("./pliki/Zdjecia/l19.png");
							l23 = al_load_bitmap("./pliki/Zdjecia/l23.png");
							znak_pyt = al_load_bitmap("./pliki/Zdjecia/znak_pyt.png");
							kop = al_load_bitmap("./pliki/Zdjecia/kop.png");
							level = 22;
						}
					}
				}
			}

			if (level == 19) {
				wyb_opcji = -1;
				gra_gui19(zeg1, level, font36, l19, l23);
				lvl19(font36, level, x, y, kop, znak_pyt);
			}

			if (level == 18) {
				wyb_opcji = -1;
				gra_gui17(zeg1, level, font36, l17, l18);
				lvl17(font36, level, x, y);
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.pressure) {
						if (x >= 1440 && y >= 400 && x <= 1600 && y <= 600) {
							l19 = al_load_bitmap("./pliki/Zdjecia/l19.png");
							l23 = al_load_bitmap("./pliki/Zdjecia/l23.png");
							znak_pyt = al_load_bitmap("./pliki/Zdjecia/znak_pyt.png");
							kop = al_load_bitmap("./pliki/Zdjecia/kop.png");
							al_destroy_bitmap(l17);
							al_destroy_bitmap(l18);
							level = 19;
						}
						if (x >= 600 && y >= 390 && x <= 850 && y <= 600) {
							l20 = al_load_bitmap("./pliki/Zdjecia/l20.png");
							l21 = al_load_bitmap("./pliki/Zdjecia/l21.png");
							al_destroy_bitmap(l17);
							al_destroy_bitmap(l18);
							level = 20;
						}
					}
				}
			}

			if (level == 17) {
				wyb_opcji = -1;
				gra_gui17(zeg1, level, font36, l17, l18);
				lvl17(font36, level, x, y);

				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.pressure) {
						if (x >= 1300 && y >= 380 && x <= 1600 && y <= 900) {
							l14 = al_load_bitmap("./pliki/Zdjecia/l14.png");
							level = 14;
						}
						else {
							level = 18;
						}
					}
				}

			}

			if (level == 16) {
				wyb_opcji = -1;
				gra_gui14(zeg1, level, font36, l14);
				lvl14(font36, level, x, y);
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.pressure) {
						if (x >= 980 && y >= 130 && x <= 1140 && y <= 550) {
							level = 14;
						}
					}
				}
			}

			if (level == 15) {
				wyb_opcji = -1;
				gra_gui14(zeg1, level, font36, l14);
				lvl14(font36, level, x, y);
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.pressure) {
						if (x >= 1300 && y >= 0 && x <= 1600 && y <= 900) {
							level = 14;
						}
						else if (x >= 740 && y >= 230 && x <= 1100 && y <= 460) {
							l18 = al_load_bitmap("./pliki/Zdjecia/l18.png");
							l17 = al_load_bitmap("./pliki/Zdjecia/l17.png");
							al_destroy_bitmap(l14);
							level = 17;
						}
					}
				}
			}

			if (level == 14) {
				wyb_opcji = -1;
				gra_gui14(zeg1, level, font36, l14);
				lvl14(font36, level, x, y);
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.pressure) {
						if (x >= 1120 && y >= 250 && x <= 1400 && y <= 650) {
							level = 15;
						}
						else if (x >= 140 && y >= 250 && x <= 689 && y <= 900) {
							level = 16;
						}
					}
				}
			}

			if (level == 13) {
				wyb_opcji = -1;
				gra_gui12a(zeg1, level, font36, l12);
				lvl12(font36, level, x, y);
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.pressure) {
						if (x >= 0 && y >= 0 && x <= 1600 && y <= 159) {
							al_destroy_bitmap(l12);
							l14 = al_load_bitmap("./pliki/Zdjecia/l14.png");
							level = 14;
						}
					}
				}
			}

			if (level == 12) {
				wyb_opcji = -1;
				gra_gui12(zeg1, level, font36, l12);
				lvl12(font36, level, x, y);
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.pressure) {
						if (x >= 0 && y >= 350 && x <= 1600 && y <= 900) {
							level = 13;
						}
						else {
							al_destroy_bitmap(l12);
							l14 = al_load_bitmap("./pliki/Zdjecia/l14.png");
							level = 14;
						}
					}
				}

			}

			if (level == 11) {
				wyb_opcji = -1;
				gra_gui7(zeg1, level, font36, pustynia_img);
				lvl7(font36, level, x, y, pustynia_img, font56, czacha);
				if (tlo_muzyka) {
					al_stop_samples(pustynia);
					al_play_sample_instance(testmuzyka);
				}
			}

			if (level == 10) {
				wyb_opcji = -1;
				gra_gui7(zeg1, level, font36, pustynia_img);
				lvl7(font36, level, x, y, pustynia_img, font56, czacha);
				
					if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
						if (ev.mouse.pressure) {
							
							if (x >= 0 && y >= 0 && x <= 510 && y <= 550) {
								level = 11;
							}
							if (x >= 515 && y >= 0 && x <= 1030 && y <= 550) {
								level = 11;
							}
							if (x >= 1035 && y >= 0 && x <= 1600 && y <= 550) {
								level = 11;
							}
						
					}
				}
			}

			if (level == 9) {
				wyb_opcji = -1;
				gra_gui7(zeg1, level, font36, pustynia_img);
				lvl7(font36, level, x, y, pustynia_img, font56, czacha);
			
					if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
						if (ev.mouse.pressure) {
							
							if (x >= 0 && y >= 0 && x <= 510 && y <= 550) {
								level = 10;
							}
							if (x >= 515 && y >= 0 && x <= 1030 && y <= 550) {
								level = 10;
							}
							if (x >= 1035 && y >= 0 && x <= 1600 && y <= 550) {
								level = 10;
							}
						}

				}
			}

			if (level == 8) {
				wyb_opcji = -1;
				gra_gui7(zeg1, level, font36, pustynia_img);
				lvl7(font36, level, x, y, pustynia_img, font56, czacha);

				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.pressure) {

						if (x >= 0 && y >= 0 && x <= 510 && y <= 550) {
							level = 9;
						}
						if (x >= 515 && y >= 0 && x <= 1030 && y <= 550) {
							level = 9;
						}
						if (x >= 1035 && y >= 0 && x <= 1600 && y <= 550) {
							level = 9;
						}
					}

				}
			}

			if (level == 7) {
				wyb_opcji = -1;
				gra_gui7(zeg1, level, font36, pustynia_img);
				lvl7(font36, level, x, y, pustynia_img, font56, czacha);
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.pressure) {
						
						if (x >= 0 && y >= 0 && x <= 510 && y <= 550) {
							level = 8;
						}
						if (x >= 515 && y >= 0 && x <= 1030 && y <= 550) {
							level = 8;
						}
						if (x >= 1035 && y >= 0 && x <= 1600 && y <= 550) {
							level = 8;
						}
					}
				}
			}

			if (level == 6) {
				wyb_opcji = -1;
				lvl6(font56, level, rakieta_img, x, y, astro);
			}

			if (level == 5) {
				wyb_opcji = -1;
				gra_gui5(zeg1, level, l5, l5a, rakieta, r_tlo, r_tlo2, r_tv, rakieta_img, rot_rak);
				lvl5(font36, level, x, y, rakieta, rot_rak);
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.pressure) {

						if (x >= 600 && y >= 430 && x <= 620 && y <= 455) {
							al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
							al_play_sample(sterownia, volume * 10, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
							rakieta = true;
						}
						if (rakieta) {
							if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
								if (ev.mouse.pressure) {

									if (x >= 800 && y >= 730 && x <= 880 && y <= 875) {
										//l 15%
										al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										rot_rak -= 5;
									}
									if (x >= 950 && y >= 700 && x <= 1070 && y <= 888) {
										//l 30%
										al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										rot_rak -= 10;
									}
									if (x >= 1150 && y >= 700 && x <= 1220 && y <= 855) {
										//p 30%
										al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										rot_rak += 10;
									}
									if (x >= 1240 && y >= 700 && x <= 1320 && y <= 855) {
										//p 15%
										al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										rot_rak += 5;
									}
									if (x >= 1340 && y >= 700 && x <= 1420 && y <= 855) {
										//p 5%
										al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										rot_rak += 1;
									}
									if (x >= 1560 && y >= 430 && x <= 1580 && y <= 470) {
										al_play_sample(rakieta_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										al_stop_samples(sterownia);

										if (rot_rak < 0 || rot_rak > 0) {
											rakieta_img = al_load_bitmap("./pliki/Zdjecia/rakieta.png");
											l23 = al_load_bitmap("./pliki/Zdjecia/l23.png");
											l19 = al_load_bitmap("./pliki/Zdjecia/l19.png");
											al_destroy_bitmap(l5);
											al_destroy_bitmap(l5a);
											al_destroy_bitmap(r_tlo);
											al_destroy_bitmap(r_tlo2);
											al_destroy_bitmap(r_tv);
											al_destroy_sample(sterownia);
											level = 23;
										}
										else {
											rakieta_img = al_load_bitmap("./pliki/Zdjecia/rakieta.png");
											astro = al_load_bitmap("./pliki/Zdjecia/astro.png");
											al_destroy_bitmap(l5);
											al_destroy_bitmap(l5a);
											al_destroy_bitmap(r_tlo);
											al_destroy_bitmap(r_tlo2);
											al_destroy_bitmap(r_tv);
											al_destroy_sample(sterownia);
											level = 6;
										}

									}
								}
							}
						}
					}

				}
			}

			if (level == 4) {
				wyb_opcji = -1;
				gra_gui4(zeg1, level, l4);
				lvl4(font56, level, x, y);
			}

			if (level == 3) {
			wyb_opcji = -1;
			gra_gui3(zeg1, level, piwnica_bool, font36, l3, kor1_img, kor2_img, kor3_img, kor4_img, azorek_bool, czibo_bool, korek_bool, rybka_bool);
			lvl3(font36, level, x, y, azorek_bool, rybka_bool, czibo_bool, korek_bool, wybor_level3);

			
					if (kod_lvl3[2] == 1 && kod_lvl3[0] == 2 && kod_lvl3[1] == 3 && kod_lvl3[3] == 4) {
						al_play_sample(open, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
						al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 750, 0, "'Zamek wydaje d^wi`k'");
					}
					if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
						if (ev.mouse.pressure) {
							
							level3_podejscia++;
							if (azorek_bool && rybka_bool && korek_bool && czibo_bool) {
									kod_lvl3[0] = 0;
									kod_lvl3[1] = 0;
									kod_lvl3[2] = 0;
									kod_lvl3[3] = 0;
									ikod_lvl3 = 0;
								
							}
							if (x >= 270 && y >= 210 && x <= 440 && y <= 435) {
								al_play_sample(obrazek_ruch, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								if (azorek_bool) {
									azorek_bool = false;
									wybor_level3 = 1;
									kod_lvl3[ikod_lvl3] = 1;
									ikod_lvl3++;
								}
								else {
									azorek_bool = true;
									wybor_level3 = 0;
								}
							}
							if (x >= 670 && y >= 120 && x <= 860 && y <= 345) {
								al_play_sample(obrazek_ruch, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								if (rybka_bool) {
									rybka_bool = false;
									wybor_level3 = 2;
									kod_lvl3[ikod_lvl3] = 2;
									ikod_lvl3++;
								}
								else {
									rybka_bool = true;
									wybor_level3 = 0;
								}
								
							}
							if (x >= 960 && y >= 35 && x <= 1130 && y <= 270) {
								al_play_sample(obrazek_ruch, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								if (czibo_bool) {
									czibo_bool = false;
									wybor_level3 = 3;
									kod_lvl3[ikod_lvl3] = 3;
									ikod_lvl3++;
								}
								else {
									czibo_bool = true;
									wybor_level3 = 0;
								}
								 
								 
							}
							if (x >= 900 && y >= 271 && x <= 1120 && y <= 445) {
								al_play_sample(obrazek_ruch, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								if (korek_bool) {
									korek_bool = false;
									wybor_level3 = 4;
									kod_lvl3[ikod_lvl3] = 4;
									ikod_lvl3++;
								}
								else {
									korek_bool = true;
									wybor_level3 = 0;
								}
							}
							if (level3_podejscia == 20) {
								l4 = al_load_bitmap("./pliki/Zdjecia/l4.png");
								al_destroy_bitmap(l3);
								al_destroy_bitmap(kor1_img);
								al_destroy_bitmap(kor2_img);
								al_destroy_bitmap(kor3_img);
								al_destroy_bitmap(kor4_img);
								level = 4;
								tlo_muzyka = false;
								al_stop_samples(tlo_domek);
								al_destroy_sample(tlo_domek);
								al_play_sample_instance(testmuzyka);
							}
							
							if (x >= 1180 && y >= 0 && x <= 1600 && y <= 755) {
								al_play_sample(open, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
								if (kod_lvl3[2] == 1 && kod_lvl3[0] == 2 && kod_lvl3[1] == 3 && kod_lvl3[3] == 4) {
									l5 = al_load_bitmap("./pliki/Zdjecia/l5.png");
									l5a = al_load_bitmap("./pliki/Zdjecia/l5a.png");
									rakieta_img = al_load_bitmap("./pliki/Zdjecia/rakieta.png");
									r_tlo = al_load_bitmap("./pliki/Zdjecia/rakieta_tlo.png");
									r_tlo2 = al_load_bitmap("./pliki/Zdjecia/rakieta_tlo2.png");
									r_tv = al_load_bitmap("./pliki/Zdjecia/rakieta_tv.png");
									al_destroy_bitmap(l3);
									al_destroy_bitmap(kor1_img);
									al_destroy_bitmap(kor2_img);
									al_destroy_bitmap(kor3_img);
									al_destroy_bitmap(kor4_img);
									sterownia = al_load_sample("./pliki/muzyka/zapsplat_technology_video_game_nintendo_wii_console_on_disc_spin_off_66805.mp3");
									level = 5;
									al_play_sample(open, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
									al_destroy_sample(open);
									if (tlo_muzyka) {
										al_stop_samples(tlo_domek);
										al_destroy_sample(tlo_domek);
										al_play_sample_instance(testmuzyka);
										tlo_muzyka = false;
									}
								
								}
								else {
									ikod_lvl3 = 0;
								}
							}
					}
				}
			}

			if (level == 2) {
				wyb_opcji = -1;
				gra_gui2(zeg1, level, font36, l2, obraz_tv, tv_img);
				lvl2(font36, level, x, y, obraz_tv);
			
					if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
						if (ev.mouse.pressure) {
							
							if (ev.mouse.button & 1) { //lewy
								
								if (x >= 452 && y >= 100 && x <= 760 && y <= 560) {
									l3 = al_load_bitmap("./pliki/Zdjecia/l3.png");
									kor1_img = al_load_bitmap("./pliki/Zdjecia/a.png");
									kor2_img = al_load_bitmap("./pliki/Zdjecia/b.png");
									kor3_img = al_load_bitmap("./pliki/Zdjecia/c.png");
									kor4_img = al_load_bitmap("./pliki/Zdjecia/d.png");
									al_destroy_bitmap(tv_img);
									al_destroy_bitmap(l2);
									open = al_load_sample("./pliki/muzyka/zapsplat_technology_vr_headset_focus_slider_single_movement_19160.mp3");
									level = 3;
								}
								if (obraz_tv) {
									obraz_tv = false;
								}
								if (x >= 990 && y >= 430 && x <= 1150 && y <= 510 && !obraz_tv) {
									
									obraz_tv = true;
								}
							}
						}
				}
			}

			if (level == 1) {
				wyb_opcji = -1;
				gra_gui1(zeg1, level, font36, l1, zamek_bool, zamek_img, zamek_kod);
				lvl1_a(font36, level, x, y, zamek_bool);
				
					if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
						if (ev.mouse.pressure) {
							
							if (ev.mouse.button & 1) { //lewy
								if (x >= 740 && y >= 400 && x <= 780 && y <= 460 && !zamek_bool) {
									zamek_bool = true;
									
								}
								if (i_kod <= 5) {
									if (x >= 620 && y >= 200 && x <= 680 && y <= 230 && zamek_bool) {
										al_play_sample(zamek_klik, volume*6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										i_kod++;
										zamek_kod[i_kod] = 1;				
									}
									if (x >= 690 && y >= 200 && x <= 740 && y <= 230 && zamek_bool) {
										al_play_sample(zamek_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										i_kod++;
										zamek_kod[i_kod] = 2;	
									}
									if (x >= 620 && y >= 250 && x <= 680 && y <= 280 && zamek_bool) {
										al_play_sample(zamek_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										i_kod++;
										zamek_kod[i_kod] = 3;
									}
									if (x >= 690 && y >= 250 && x <= 740 && y <= 280 && zamek_bool) {
										al_play_sample(zamek_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										i_kod++;
										zamek_kod[i_kod] = 4;
									}
									if (x >= 620 && y >= 290 && x <= 680 && y <= 325 && zamek_bool) {
										al_play_sample(zamek_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										i_kod++;
										zamek_kod[i_kod] = 5;
									}
									if (x >= 690 && y >= 290 && x <= 740 && y <= 325 && zamek_bool) {
										al_play_sample(zamek_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										i_kod++;
										zamek_kod[i_kod] = 6;
									}
									if (x >= 620 && y >= 340 && x <= 680 && y <= 370 && zamek_bool) {
										al_play_sample(zamek_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										i_kod++;
										zamek_kod[i_kod] = 7;
									}
									if (x >= 690 && y >= 340 && x <= 740 && y <= 370 && zamek_bool) {
										al_play_sample(zamek_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										i_kod++;
										zamek_kod[i_kod] = 8;
									}
									if (x >= 620 && y >= 380 && x <= 680 && y <= 410 && zamek_bool) {
										al_play_sample(zamek_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										i_kod++;
										zamek_kod[i_kod] = 9;
									}
									if (x >= 690 && y >= 380 && x <= 740 && y <= 410 && zamek_bool) {
										al_play_sample(zamek_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
										i_kod++;
										zamek_kod[i_kod] = 0;
									}
								}
								if (x >= 620 && y >= 430 && x <= 680 && y <= 460 && zamek_bool) {
									al_play_sample(zamek_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

									if (zamek_kod[1] == 3 && zamek_kod[2] == 0 && zamek_kod[3] == 4 && zamek_kod[4] == 9) {
										l2 = al_load_bitmap("./pliki/Zdjecia/l2.png");
										tv_img = al_load_bitmap("./pliki/Zdjecia/tv.png");
										al_destroy_bitmap(l1);
										tlo_domek = al_load_sample("./pliki/muzyka/ChopinNocturne.mp3");
										level = 2;
										zamek_bool = false;
										tlo_muzyka = true;
										al_stop_sample_instance(testmuzyka);
										al_play_sample(tlo_domek, volume * 10, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
									}
								}
										
								if (x >= 690 && y >= 430 && x <= 740 && y <= 460 && zamek_bool) {
									al_play_sample(zamek_klik, volume * 6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
									i_kod = 0;
									for (int i = 0; i <= 5; i++) {
										zamek_kod[i] = 0;
									}
								}
							}
						}
					
				}
			}
			if(level == 0) {
				gra_gui0(zeg1, level, font36, lvl1);
				lvl0(font36, level, x, y);
				


					if (x >= 50 && y >= 200 && x <= 1054 && y <= 249) {
						wyb_opcji = 0;
					}
					if (x >= 50 && y >= 250 && x <= 1054 && y <= 299) {
						wyb_opcji = 1;
					}
					if (x >= 50 && y >= 300 && x <= 1054 && y <= 349) {
						wyb_opcji = 2;
					}


					if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
						if (ev.mouse.pressure) {
							
							if (ev.mouse.button & 1) { //lewy

								if (wyb_opcji == 0 && !menu && x >= 50 && y >= 200 && x <= 1054 && y <= 250) {
									al_stop_sample_instance(testmuzyka);
									tlo_muzyka = true;
									pustynia_img = al_load_bitmap("./pliki/Zdjecia/pustynia.jpg");
									czacha = al_load_bitmap("./pliki/Zdjecia/czacha.png");
									pustynia = al_load_sample("./pliki/muzyka/344_audio_arctic_wind_filtered_rumble_006.mp3");
									al_play_sample(pustynia, volume * 7, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
									level = 7;
								}
								if (wyb_opcji == 1 && !menu && x >= 50 && y >= 250 && x <= 1054 && y <= 300) {
									l1 = al_load_bitmap("./pliki/Zdjecia/l1.png");
									zamek_img = al_load_bitmap("./pliki/Zdjecia/zamek.png");
									level = 1;
								
								}
								if (wyb_opcji == 2 && !menu && x >= 50 && y >= 300 && x <= 1054 && y <= 350) {
									l12 = al_load_bitmap("./pliki/Zdjecia/l12.png");
									level = 12;
								}

							}
						}

					}

				
			}
			


			switch (wyb_opcji)
			{
			case 0:
				al_draw_filled_rounded_rectangle(40, 200, 1050, 250, 20, 20, al_map_rgba(222, 96, 38, 50));
				al_draw_text(font36, al_map_rgb(0, 230, 54), 50, 200, 0, ">");
				break;
			case 1:
				al_draw_filled_rounded_rectangle(40, 250, 1050, 300, 20, 20, al_map_rgba(222, 96, 38, 50));
				al_draw_text(font36, al_map_rgb(0, 230, 54), 50, 250, 0, ">");
				break;
			case 2:
				al_draw_filled_rounded_rectangle(40, 300, 1050, 350, 20, 20, al_map_rgba(222, 96, 38, 50));
				al_draw_text(font36, al_map_rgb(0, 230, 54), 50, 300, 0, ">");
				break;
			}
		}


		if (menu) {

			al_draw_scaled_bitmap(menu_img, 0, 0, 1580, 832, 0, 0, 1600, 900, 0);
			//  x1   y1  x2   y2   rx  ry
			//al_draw_filled_rounded_rectangle(20, 800, 350, 855, 20, 20, al_map_rgba(0, 0, 0, 100));
			al_draw_filled_rounded_rectangle(700, 170, 1050, 400, 20, 20, al_map_rgba(0, 0, 0, 100));
			al_draw_text(font36, al_map_rgb(33, 14, 201), 750, 200, 0, "Rozpocznij gr`");
			al_draw_text(font36, al_map_rgb(33, 14, 201), 770, 250, 0, "Opcje");
			al_draw_text(font36, al_map_rgb(33, 14, 201), 800, 300, 0, "WyjYcie");
			//al_draw_text(font36, al_map_rgb(0, 230, 54), 30, 808, 0, "Zatwierd^: ENTER");


				if (x >= 750 && y >= 200 && x <= 1010 && y <= 249) {
					mysz = 0;
					strzalka = mysz;
				}
				if (x >= 770 && y >= 250 && x <= 1010 && y <= 299) {
					mysz = 1;
					strzalka = mysz;
				}
				if (x >= 800 && y >= 300 && x <= 1010 && y <= 349) {
					mysz = 2;
					strzalka = mysz;
				}


				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.pressure) {
						
						if (ev.mouse.button & 1) { //lewy

							if (strzalka == 0 && menu && x >= 750 && y >= 200 && x <= 1010 && y <= 249) {
								gra = true;
								menu = false;
								lvl1 = al_load_bitmap("./pliki/Zdjecia/lvl1.png");
							}
							if (strzalka == 1 && menu && x >= 770 && y >= 250 && x <= 1010 && y <= 299) {
								gra = false;
								menu = false;
								strzalka_opcje = -1;
							}
							if (strzalka == 2 && menu && x >= 800 && y >= 300 && x <= 1010 && y <= 349) {
								exit = true;
							}

						}
					

				}

			}

			//==== 

			switch (strzalka)
			{
			case 0:
				al_draw_filled_rounded_rectangle(710, 200, 1040, 250, 20, 20, al_map_rgba(222, 96, 38, 50));
				break;
			case 1:
				al_draw_filled_rounded_rectangle(710, 250, 1040, 300, 20, 20, al_map_rgba(222, 96, 38, 50));
				break;
			case 2:
				al_draw_filled_rounded_rectangle(710, 300, 1040, 350, 20, 20, al_map_rgba(222, 96, 38, 50));
				break;
			case 3:
				al_draw_text(font36, al_map_rgb(0, 230, 54), 670, 350, 0, ">");
				break;
			}

			al_draw_filled_rounded_rectangle(10, 10, 150, 50, 20, 20, al_map_rgba(0, 0, 0, 100));
			al_draw_text(font16, al_map_rgb(3, 252, 23), 23, 22, 0, " Gra ver.F1NAL");


			//	al_rest(0.1);
		}
		al_flip_display(timer);

	}
	al_destroy_display(display);
	al_destroy_bitmap(menu_img);
	al_destroy_sample(muzyka);
	al_destroy_sample(zamek_klik);
	al_destroy_sample(obrazek_ruch);
	al_destroy_sample(rakieta_klik);
	al_destroy_sample(kod_bunkier_ok);
}

