int f(int x) { return (x + 3) % 7; } /* exemplo de funcao */

int floyd(int x0) {
		int t, h, len, first;

		/* encontra repeticao */
		t = f(x0);
		h = f(f(x0));
		while(t != h) {
			t = f(t);
			h = f(f(h));
		}

		/* encontra a posicao do primeiro ciclo (opcional) */
		first = 0;
		h = t;
		t = x0;
		while(t != h) {
			t = f(t);
			h = f(h);
			first++;
		}

		/* encontra o tamanho ciclo (opcional) */
		length = 1;
		h = f(t);
		while(t != h) {
			h = f(h);
			length++;
		}

		return length;
}
