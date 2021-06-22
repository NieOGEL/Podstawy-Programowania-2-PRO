/*
==Jak to czytać==
 
Q = Ł | Y = ś | ^ = ź
V = ó | [ = ł | _ = ż
X = ą | ` = ę | ~ = ń
= = Ś | @ = ć
*/

char* text_wyb(int level, int part) {
	
	//LVL 0
	if (level == 0) {
		if (part == 1) {
			char* text = "Nie mam nic do stracenia... ''Id^ przed siebie''";
			return text;
		}
		if (part == 2) {
			char* text = "Co to za domek? ''Podejd^ do domu''";
			return text;
		}
		if (part == 3) {
			char* text = "Zawsze na zachVd ka_dy to wie prawda? ''Id^ na zachVd''";
			return text;
		}
	}

	//LVL 1
	if (level == 1){
		if (part == 1) {
			char* text = "Wybor";
			return text;
		}
		if (part == 2) {
			char* text = "wybor";
			return text;
		}
		if (part == 3) {
			char* text = "wybor";
			return text;
		}
	}

}
char* text_opis(int level, int part, int l_part) {

	//LVL 0
	if (level == 0 && part == 1) {
		char* text = "Gdzie ja jestem?! Pustynia!! tylko tego brakowa[o...";
		return text;
	}
	if (level == 0 && part == 2) {
		char* text = "Przynajmniej nie jestem w Radomiu...";
		return text;
	}
	//LVL 1
	if (level == 1) {
		switch (l_part) {
		case 0:
			if (part == 1) {
				char* text = "Co tu si` sta[o?  Wszystko wyglXda jak po wybuchu...";
				return text;
			}
			if (part == 2) {
				char* text = "Hmmm...";
				return text;
			}
			break;
		case 1:
			if (part == 1 && l_part == 1) {
				char* text = "To musia[ by@ dobry opel";
				return text;
			}
			if (part == 2 && l_part == 1) {
				char* text = "Przynajmniej zachowa[y si` tablice...";
				return text;
			}
			break;
		}

	}

	
	
}