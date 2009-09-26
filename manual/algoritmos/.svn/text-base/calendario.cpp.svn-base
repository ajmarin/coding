#define isBissexto(y) ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))

int diasAno(int y) {
	return isBissexto(y) ? 366 : 365;
}

int diasMes(int m, int y) {
	switch(m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			return isBissexto(y) ? 29 : 28;
	}
	return -1;
}

int getdia(int d, int m, int y) {
	int ano, mes, dia, r;
	r = 0;
	for(ano = 1900; ano < y; ano++) r += diasAno(ano);
	for(mes = 1; mes < m; mes++) r += diasMes(mes, ano);
	r += d-1;
	return r;
}
