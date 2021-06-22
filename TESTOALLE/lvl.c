#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdbool.h>

void lvl0(ALLEGRO_FONT* font36, int level, int x ,int y) {
	if (level == 0) {

		//dialog
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Gdzie ja jestem?! Pustynia!! tylko tego brakowa[o...");

		//wybor
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 70, 200, 0, "Nie mam nic do stracenia... ''Id^ przed siebie''");
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 70, 250, 0, "Co to za domek? ''Podejd^ do domu''");
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 70, 300, 0, "Zawsze na zachVd ka_dy to wie prawda ? ''Id^ na zachVd''");
	}

}

void lvl1_a(ALLEGRO_FONT* font36, int level, int x, int y, bool zamek_bool) {
	if (level == 1 && !zamek_bool) {
		if (x >= 0 && y >= 0 && x <= 500 && y <= 775) {

			//dialog
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Aby z[ama@ takie drzewo");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Potrzeba naprawd` ogromnej si[y");
		} else if (x >= 1290 && y >= 400 && x <= 1599 && y <= 650) {

			//dialog
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "To musia[ by@ dobry opel");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Przynajmniej zachowa[y si` tablice...");
		} else if (x >= 740 && y >= 400 && x <= 780 && y <= 460) {
			//dialog
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Elektroniczny zamek w takiej ruderze!!");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Problem w tym _e potrzebny jest jakiY kod");
		}
		else {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Co tu si` sta[o?  Wszystko wyglXda jak po wybuchu...");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Hmmm...");
		}

	}
	if (level == 1 && zamek_bool) {
		//dialog
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Fajnie Fajnie...");
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Problem w tym _e potrzebny jest kod");
	}

}

void lvl2(ALLEGRO_FONT* font36, int level, int x, int y, bool obraz_tv) {

	if (level == 2 && !obraz_tv) {
		if (x >= 0 && y >= 0 && x <= 449 && y <= 557 || x >= 770 && y >= 0 && x <= 940 && y <= 557) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "O panie ALE BAJZEL. Niczym po w[amaniu...");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Zastanawia mnie tylko kto p[aci za prXd w takim miejscu.");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Zbadam ten dom mo_e si` czegoY dowiem");
		}
		else if (x >= 450 && y >= 100 && x <= 760 && y <= 560) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Korytarz mo_e tam coY znajd`");
		}
		else if (x >= 951 && y >= 0 && x <= 1600 && y <= 905) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Gdyby dostroi@ antene...");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "mo_e by coY z tego by[o");
		}
		else {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "AHH Muzyka klasyczna uspokaja...");
		}
	}
	if (level == 2 && obraz_tv) {
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Jaki koniec Ywiata co to za g[upoty");
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Schron schron gdzie ja znajde jakiY schron...");
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "2Dni od kiedy?!");
	}
}

void lvl3(ALLEGRO_FONT* font36, int level, int x, int y, bool azorek, bool rybka, bool czibo, bool kotek, int wybor){
	if (x >= 0 && y >= 0 && x <= 1175 && y <= 755) {

		if (level == 3 && azorek && rybka && czibo && kotek || level == 3 && wybor == 0) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "W[aYciciel mia[ gust... ");
				al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Wszystko jest w pyle... ");
				al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "CiXgle dr`czy mnie myYl 2 Dni");
		}

		if (!azorek && wybor == 1) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Azroek jest faworytem tego zestawienia");
		}
		if (!rybka && wybor == 2) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "''OGONEK'' ciekawe imie dla z[otej rybki");
		}
		if (!czibo && wybor == 3) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Hmm... Wiesza@ reklame na Ycianie? Nie mVj styl");
		}
		if (!kotek && wybor == 4) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Jaki Yliczny kotek");
		}
	}
	if (x >= 1180 && y >= 0 && x <= 1600 && y <= 755) {
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Znowu jakiY kod...");
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Drzwi do piwnicy co tam mo_e by@?");
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Zaczyna Ywita@!!! Sp`dzi[em tu ca[X noc??!");
	}

}
void lvl4(ALLEGRO_FONT* font36, int level, int x, int y) {
	al_draw_textf(font36, al_map_rgb(235, 239, 245), 5, 400, 0, "Przegrana!");
	al_draw_textf(font36, al_map_rgb(235, 239, 245), 5, 490, 0, "Zako~czenie 1# Wybuch (Min`[y 2 Dni)");
	al_draw_textf(font36, al_map_rgb(235, 239, 245), 5, 550, 0, "Wyjd^");
}
void lvl5(ALLEGRO_FONT* font36, int level, int x, int y, bool rakieta, int a) {

	if (!rakieta) {

		if (x >= 275 && y >= 240 && x <= 534 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Panel jak w reaktorze w Czarnobylu");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Oby tylko nie wybuch[o!!!");
		} else if (x >= 552 && y >= 250 && x <= 680 && y <= 520) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Hmm... ");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Czerwony guzik a_ prosi si` aby go u_y@");
		} else if (x >= 700 && y >= 0 && x <= 1170 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Zegary... Co to za maszyna");
		}
		else {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "A co to za ustrojstwa niczym sterownia rakiety!");
		}
	}
	else {
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 812, 88, 0, "Pozycja Rakiety -> %d",a);
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 812, 120, 0, "Wymagana pozycja -> 0");

		if (x >= 0 && y >= 0 && x <= 705 && y <= 900 && a != 0) {
			al_draw_textf(font36, al_map_rgb(12, 237, 5), 150, 610, 0, "O panie nie jestem in_ynierem!!");
		}
		if (a < 0) {
			al_draw_textf(font36, al_map_rgb(12, 237, 5), 150, 570, 0, "EHH Wystarczy skalibrowa@ tak?");
		}
		if (a > 0) {
			al_draw_textf(font36, al_map_rgb(12, 237, 5), 150, 570, 0, "To nie jest takie [atwe...");
		}
		if (a == 0) {
			al_draw_textf(font36, al_map_rgb(12, 237, 5), 812, 450, 0, "Pozycja Poprawna <START>");
			
			if (x >= 1560 && y >= 430 && x <= 1580 && y <= 470) {
				al_draw_textf(font36, al_map_rgb(12, 237, 5), 150, 570, 0, "To Lecim! za Szczecin");
			}
			else {
				al_draw_textf(font36, al_map_rgb(12, 237, 5), 150, 570, 0, "Wi`c wystarczy nacisnX@ Start?");
			}
		}
	}
	
}

void lvl6(ALLEGRO_FONT* font36, int level, ALLEGRO_BITMAP* rakieta_img, int x, int y, ALLEGRO_BITMAP* astro) {
	if (level == 6) {
		al_draw_bitmap(astro, 0, 0, 0);
		float w = al_get_bitmap_width(rakieta_img);
		float h = al_get_bitmap_height(rakieta_img);
		al_draw_rotated_bitmap(rakieta_img, w / 2, h / 2, x, y, 90, 0);

		al_draw_textf(font36, al_map_rgb(12, 237, 5), 500, 570, 0, "Zako~czenie #2 (Zniczenie asteroidy)");
	}
}

void lvl7(ALLEGRO_FONT* font36, int level, int x, int y, ALLEGRO_BITMAP* pustynia, ALLEGRO_FONT* font56, ALLEGRO_BITMAP* czacha) {
	if (level == 7) {
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Padam ze zm`czenia a ide ju_ jakieY 40 minut");
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "CoY si` mieni na niebie wyglXda jak samolot");
		if (x >= 0 && y >= 0 && x <= 510 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Chyba pVjd` w lewo");
		} else if (x >= 515 && y >= 0 && x <= 1030 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Chyba pVjd` prosto");
		} else if (x >= 1035 && y >= 0 && x <= 1600 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Chyba pVjd` w prawo");
		}
	}
	if (level == 8) {
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Ide i ide i dojY@ nie mog`");
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Ten Samolot robi si` dziwnie du_y...");
		if (x >= 0 && y >= 0 && x <= 510 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Musz` gdzieY dojY@ jak pVjd` w lewo");
		} else if (x >= 515 && y >= 0 && x <= 1030 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Musz` gdzieY dojY@ jak pVjd` prosto");
		} else if (x >= 1035 && y >= 0 && x <= 1600 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Musz` gdzieY dojY@ jak pVjd` w prawo");
		}
	}
	if (level == 9) {
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "D[u_ej ju_ nie dam rady. Jestem wyko~czony tX wyprawX");
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Na szcz`Ycie w pore znalaz[em namiot bo akurat robi si` ciemno");
		if (x >= 0 && y >= 0 && x <= 510 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Gdy wstan` ruszam w lewo");
		} else if (x >= 515 && y >= 0 && x <= 1030 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Gdy wstan` ruszam prosto");
		} else if (x >= 1035 && y >= 0 && x <= 1600 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Gdy wstan` ruszam w prawo");
		}
	}
	if (level == 10) {
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "JeYli nic nie znajd` to po mnie!!");
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "CoY mi si` wydaje _e to nie jest zwyk[y samolot");
		if (x >= 0 && y >= 0 && x <= 510 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Resztkami si[ ruszam w lewo");
		} else if (x >= 515 && y >= 0 && x <= 1030 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Resztkami si[ ruszam prosto");
		} else if (x >= 1035 && y >= 0 && x <= 1600 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Resztkami si[ ruszam w prawo");
		}
	}
	if (level == 11) {
		al_draw_textf(font56, al_map_rgb(72, 61, 139), 135, 100, 0, "Zako~czenie 3# (Pad[ z wyczerpania)");
		al_draw_textf(font56, al_map_rgb(72, 61, 139), 135, 150, 0, "Tak czy siak asteroida spad[a po 13 godzinach...");
		float w = al_get_bitmap_width(czacha);
		float h = al_get_bitmap_height(czacha);
		al_draw_rotated_bitmap(czacha, w / 2, h / 2, x, y, 0, 0);
	}

}

void lvl12(ALLEGRO_FONT* font36, int level, int x, int y) {
	//dialog
	if (level == 12) {
		if (x >= 0 && y >= 350 && x <= 1600 && y <= 900) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Krzaki... na pustyni!?");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Wydaje mi si` _e tej pustyni tu nie by[o...");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Podejd^ do krzaka");
		}
		else {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "W oddali wida@ las");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "W tym lesie musz` coY znale^@");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "W drog` idziemy do lasu!!");
		}
	}
	if (level == 13) {
		if (x >= 0 && y >= 160 && x <= 1600 && y <= 900) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Bardzo [adny krzak jest zielony...");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Dziwne bo na pustyni raczej nie rosnX tak zielone roYliny");
		}
		else {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "W oddali dalej wida@ las");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Krzaki zbadane mog` rusza@ dalej!");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "W drog` idziemy do lasu!!");
		}
	}

}
void lvl14(ALLEGRO_FONT* font36, int level, int x, int y) {
	if (level == 14) {
		if (x >= 1120 && y >= 250 && x <= 1400 && y <= 650) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Domek nr 14 wyglXda obiecujXco");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Wejd^ do Yrodka");
		}
		else if (x >= 140 && y >= 250 && x <= 689 && y <= 900) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Mo_e w tych dwVch domkach coY znajd`");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Zbadaj tamte dwa domki");
		}
		else {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Tak jak myYla[em obozowisko...");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Szkoda _e opuszczone. Ehh lepszy rydz ni_ nic...");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Warto si` tu rozejrze@");
		}
	}
	if (level == 15) {
		if (x >= 195 && y >= 280 && x <= 315 && y <= 430) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Sztuka nowoczesna dodaje uroku temu pomieszczeniu");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Raczej nic wa_nego...");
		}
		else if (x >= 1300 && y >= 0 && x <= 1600 && y <= 900) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Nic tu nie ma");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Wyjd^ z budynku");
		}
		else if (x >= 740 && y >= 230 && x <= 1100 && y <= 460) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Nic tu nie ma");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Wyjd^ z budynku oknem");
		} 
		else {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Ten dom jest mniejszy ni_ wyglXda");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Pewnie jeden z ta~szych");
		}
	}
	if (level == 16) {
		if (x >= 120 && y >= 137 && x <= 370 && y <= 280) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Ten obraz musi by@ warty miliony");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Raczej nic wa_nego...");
		}
		else if (x >= 980 && y >= 130 && x <= 1140 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Nic tu nie ma");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Wyjd^ z budynku");
		}
		else {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "To miejsce musia[o by@ bardzo popularne... Gdy dzia[a[o.");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Luksusowe tapczany i te kolory Ycian!");
		}
	}
}
void lvl17(ALLEGRO_FONT* font36, int level, int x, int y) {
	if (level == 17) {
		if (x >= 1300 && y >= 380 && x <= 1600 && y <= 900) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "WrV@ do obozu");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "EEE... Po co tam wraca@");
		}
		else {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Wi`c w drog`!!");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Id^ przed siebi`");
		}
	}
	if (level == 18) {
		if (x >= 1440 && y >= 400 && x <= 1600 && y <= 600) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Jakiej Poczcie... Jaki kod!!!");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Id^ poszuka@ Poczty");
		}
		else if (x >= 600 && y >= 390 && x <= 850 && y <= 600) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Wejd^ do Yrodka");
		}
		else {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Prosz` Prosz` Jaki pi`kny schron");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Ciekawe co jest w Yrodku?");
		}
	}
}

void lvl19(ALLEGRO_FONT* font36, int level, int x, int y, ALLEGRO_BITMAP* kop, ALLEGRO_BITMAP* pyt) {
	if (level== 19) {
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Zako~czenie #4 (Gdy szukasz poczty uwa_aj na asteroidy)");
		float w = al_get_bitmap_width(kop);
		float h = al_get_bitmap_height(kop);
		al_draw_rotated_bitmap(kop, w / 2, h / 2, x, y, 0, 0);
	}
	if (level == 22) {
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Gdy wychodzi[eY asteroida uderzy[a w Ziemi`)");
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Zako~czenie #5 (CoY musia[em pominX@...)");
		float w = al_get_bitmap_width(pyt);
		float h = al_get_bitmap_height(pyt);
		al_draw_rotated_bitmap(pyt, w / 2, h / 2, x, y, 0, 0);
	}
}

void lvl20(ALLEGRO_FONT* font36, int level, int x, int y) {
	if (level == 20) {
		if (x >= 1050 && y >= 260 && x <= 1236 && y <= 415) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "KOD!!! SkXd go mam wziX@");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "SprVbuj` mo_e si` uda");
		}
		else if (x >= 581 && y >= 0 && x <= 1030 && y <= 600) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Zamkni`te... Sam tego nie wyrw`");
		}
		else if (x >= 1320 && y >= 0 && x <= 1600 && y <= 900) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Wyjd^ w poszukiwaniu kodu");
		}
		else {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Co to za plakaty!!");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "2 Dni od kiedy!!");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Nie wa_ne musze ukry@ si` w tym schronie");
		}
	}
	if (level == 21) {
		if (x >= 1180 && y >= 55 && x <= 1450 && y <= 300) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Kod Pocztowy?!");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "PAZFL co to ma znaczy@");
		
		}
		else if (x >= 1280 && y >= 500 && x <= 1420 && y <= 550) {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "OK Zobaczmy czy dzia[a");
		}
		else {
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "0 prVb ostatnia szansa aby to otworzy@");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Powoli wystarczy si` skupi@ prawda?");
			al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 700, 0, "Hmmm... Ekran jest dotykowy!!!");
		}
	}

}

void lvl23(ALLEGRO_FONT* font36, int level, int x, int y, ALLEGRO_BITMAP* bunkier) {
	
	if (level == 23) {
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Rakieta skierowana w Ycian` to nie by[ dobry plan");
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Zako~czenie #6 (Nie strzelaj rakietami w Yciany!!)");
		float w = al_get_bitmap_width(bunkier);
		float h = al_get_bitmap_height(bunkier);
		al_draw_rotated_bitmap(bunkier, w / 2, h / 2, x, y, 0, 0);
	}
	if (level == 24) {
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 600, 0, "Dok[adnie 2 minuty po wejYciu Asteroida spad[a na Ziemi`");
		al_draw_textf(font36, al_map_rgb(72, 61, 139), 135, 650, 0, "Zako~czenie #8 Bunkry przetrwajX wszystko");
		float w = al_get_bitmap_width(bunkier);
		float h = al_get_bitmap_height(bunkier);
		al_draw_rotated_bitmap(bunkier, w / 2, h / 2, x, y, 0, 0);
	}
	if (level == 25) {
		al_draw_textf(font36, al_map_rgb(30, 199, 38), 300, 660, 0, "Zamek si` wy[Xczy[, a ziemia zosta[a zniszczona");
		al_draw_textf(font36, al_map_rgb(30, 199, 38), 300, 730, 0, "Zako~czenie #9 (KtoY wykorzysta[ wszystkie prVby...)");
		float w = al_get_bitmap_width(bunkier);
		float h = al_get_bitmap_height(bunkier);
		al_draw_rotated_bitmap(bunkier, w / 2, h / 2, x, y, 0, 0);
	}
}
/*
==Jak to czytaæ==

Q = £ | Y = œ | ^ = Ÿ
V = ó | [ = ³ | _ = ¿
X = ¹ | ` = ê | ~ = ñ
= = Œ | @ = æ
*/