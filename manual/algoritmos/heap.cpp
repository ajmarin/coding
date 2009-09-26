#define pai(i) (((i)-1)>>1)
#define esq(i) (((i)<<1)+1)
#define dir(i) (((i)<<1)+2)

template <class T> struct heap {
	T h[MAXHEAP];			/* heap (de maximo) */
	int n;					/* numero de elementos */

	void clear() { n = 0; }

	void sobe(int i) {
		if(i > 0 && h[i] > h[pai(i)])
			swap(h[pai(i)], h[i]), sobe(pai(i));
	}

	void desce(int i) {
		int fih = dir(i) < n && h[dir(i)] > h[esq(i)] ? dir(i) : esq(i);
		if(fih < n && h[fih] > h[i])
			swap(h[fih], h[i]), desce(fih);
	}

	T pop() {
		T r = h[0];
		h[0] = h[--n];
		desce(0);
		return r;
	}

	void push(T v) {
		h[n] = v;
		sobe(n++);
	}
};
