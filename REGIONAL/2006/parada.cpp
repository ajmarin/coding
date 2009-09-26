#include <cstdio>
#include <cstdlib>
#include <cstring>

#define NAO_CHAMADO -1
#define EM_EXECUCAO -2

enum instrucao { MOV, ADD, SUB, MUL, DIV, MOD, IFEQ, IFNEQ, IFG, IFL, IFGE, IFLE, ENDIF, CALL, RET };

struct comando {
	instrucao inst;
	int a, b;
	bool isareg, isbreg;
};

int l, n;
comando programa[128];
int chamadas[1000];
bool impossivel;

instrucao str2instrucao(char ins[8]) {
	if(strcmp(ins, "MOV") == 0) return MOV;
	else if(strcmp(ins, "ADD") == 0) return ADD;
	else if(strcmp(ins, "SUB") == 0) return SUB;
	else if(strcmp(ins, "MUL") == 0) return MUL;
	else if(strcmp(ins, "DIV") == 0) return DIV;
	else if(strcmp(ins, "MOD") == 0) return MOD;
	else if(strcmp(ins, "IFEQ") == 0) return IFEQ;
	else if(strcmp(ins, "IFNEQ") == 0) return IFNEQ;
	else if(strcmp(ins, "IFG") == 0) return IFG;
	else if(strcmp(ins, "IFL") == 0) return IFL;
	else if(strcmp(ins, "IFGE") == 0) return IFGE;
	else if(strcmp(ins, "IFLE") == 0) return IFLE;
	else if(strcmp(ins, "ENDIF") == 0) return ENDIF;
	else if(strcmp(ins, "CALL") == 0) return CALL;
	return RET;
}

int call(int v) {
	int r[10], pc, va, vb;
	for(int i = 0; i < 10; i++) r[i] = 0;

	if(chamadas[v] == EM_EXECUCAO) {
		impossivel = true;
		return -1;
	}

	chamadas[v] = EM_EXECUCAO;
	r[0] = v;

	for(pc = 0; pc < l && !impossivel; pc++) {
		switch(programa[pc].inst) {
			/* aritmeticos */
			case MOV:
				r[programa[pc].a] = programa[pc].isbreg ? r[programa[pc].b] : programa[pc].b;
				break;
			case ADD:
				r[programa[pc].a] += programa[pc].isbreg ? r[programa[pc].b] : programa[pc].b;
				while(r[programa[pc].a] < 0) r[programa[pc].a] += 1000;
				while(r[programa[pc].a] > 999) r[programa[pc].a] -= 1000;
				break;
			case SUB:
				r[programa[pc].a] -= programa[pc].isbreg ? r[programa[pc].b] : programa[pc].b;
				while(r[programa[pc].a] < 0) r[programa[pc].a] += 1000;
				while(r[programa[pc].a] > 999) r[programa[pc].a] -= 1000;
				break;
			case MUL:
				r[programa[pc].a] *= programa[pc].isbreg ? r[programa[pc].b] : programa[pc].b;
				while(r[programa[pc].a] < 0) r[programa[pc].a] += 1000;
				while(r[programa[pc].a] > 999) r[programa[pc].a] -= 1000;
				break;
			case DIV:
				vb = programa[pc].isbreg ? r[programa[pc].b] : programa[pc].b;
				if(vb > 0) {
					r[programa[pc].a] /= vb;
					while(r[programa[pc].a] < 0) r[programa[pc].a] += 1000;
					while(r[programa[pc].a] > 999) r[programa[pc].a] -= 1000;
				} else {
					r[programa[pc].a] = 0;
				}
				break;
			case MOD:
				vb = programa[pc].isbreg ? r[programa[pc].b] : programa[pc].b;
				if(vb > 0) {
					r[programa[pc].a] %= vb;
					while(r[programa[pc].a] < 0) r[programa[pc].a] += 1000;
					while(r[programa[pc].a] > 999) r[programa[pc].a] -= 1000;
				} else {
					r[programa[pc].a] = 0;
				}
				break;

			/* condicionais */
			case IFEQ:
				va = programa[pc].isareg ? r[programa[pc].a] : programa[pc].a;
				vb = programa[pc].isbreg ? r[programa[pc].b] : programa[pc].b;
				if(!(va == vb)) {
					while(programa[pc].inst != ENDIF) pc++;
					pc--;
				}
				break;
			case IFNEQ:
				va = programa[pc].isareg ? r[programa[pc].a] : programa[pc].a;
				vb = programa[pc].isbreg ? r[programa[pc].b] : programa[pc].b;
				if(!(va != vb)) {
					while(programa[pc].inst != ENDIF) pc++;
					pc--;
				}
				break;
			case IFG:
				va = programa[pc].isareg ? r[programa[pc].a] : programa[pc].a;
				vb = programa[pc].isbreg ? r[programa[pc].b] : programa[pc].b;
				if(!(va > vb)) {
					while(programa[pc].inst != ENDIF) pc++;
					pc--;
				}
				break;
			case IFL:
				va = programa[pc].isareg ? r[programa[pc].a] : programa[pc].a;
				vb = programa[pc].isbreg ? r[programa[pc].b] : programa[pc].b;
				if(!(va < vb)) {
					while(programa[pc].inst != ENDIF) pc++;
					pc--;
				}
				break;
			case IFGE:
				va = programa[pc].isareg ? r[programa[pc].a] : programa[pc].a;
				vb = programa[pc].isbreg ? r[programa[pc].b] : programa[pc].b;
				if(!(va >= vb)) {
					while(programa[pc].inst != ENDIF) pc++;
					pc--;
				}
				break;
			case IFLE:
				va = programa[pc].isareg ? r[programa[pc].a] : programa[pc].a;
				vb = programa[pc].isbreg ? r[programa[pc].b] : programa[pc].b;
				if(!(va <= vb)) {
					while(programa[pc].inst != ENDIF) pc++;
					pc--;
				}
				break;

			/* call/ret */
			case CALL:
				va = programa[pc].isareg ? r[programa[pc].a] : programa[pc].a;
				if(chamadas[va] >= 0) r[9] = chamadas[va];
				else r[9] = call(programa[pc].isareg ? r[programa[pc].a] : programa[pc].a);
				break;
			case RET:
				return chamadas[v] = programa[pc].isareg ? r[programa[pc].a] : programa[pc].a;
				break;
		}
	}
}

int main(void) {
	int i;

	while(scanf("%d %d", &l, &n)) {
		if(l == 0 && n == 0) break;

		/* init */
		impossivel = false;
		for(i = 0; i < 1000; i++) chamadas[i] = NAO_CHAMADO;

		/* input */
		for(i = 0; i < l; i++) {
			char ins[8];
			scanf("%s", ins);
			programa[i].inst = str2instrucao(ins);
			if(programa[i].inst != ENDIF) {
				if(programa[i].inst == CALL || programa[i].inst == RET) {
					char opa[8];
					scanf("%s", opa);
					programa[i].isareg = opa[0] == 'R';
					programa[i].a = opa[0] == 'R' ? opa[1] - '0' : atoi(opa);
				} else {
					char opa[8], opb[8];
					scanf(" %[^,],%[^\n]", opa, opb);
					programa[i].isareg = opa[0] == 'R';
					programa[i].a = opa[0] == 'R' ? opa[1] - '0' : atoi(opa);
					programa[i].isbreg = opb[0] == 'R';
					programa[i].b = opb[0] == 'R' ? opb[1] - '0' : atoi(opb);
				}
			}
		}

		/* processa */
		i = call(n);

		/* output */
		if(impossivel) printf("*\n");
		else printf("%d\n", i);
	}

	return 0;
}
