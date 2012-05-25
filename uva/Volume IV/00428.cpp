#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

const double conv = acos(-1) / 180.;

int main(void){
	char line[1 << 16];
	double v[4];
	double total_roof_area = 0.0;
	double total_covered_area = 0.0;
	double total_area = 0.0;

	double lot_area, lot_roof_area, lot_covered_area;
	double covered_area, roof_area, pct_covered;

	int lot_count = 0, pos = 0, roof;

	puts("Roof Area     Floor Area     % Covered");
	puts("---------     ----------     ---------");

	while(scanf("%lf", &lot_area) == 1){
		lot_roof_area = lot_covered_area = 0.0;
		roof = 0;
		while((gets(line) && *line) || pos || !roof){
			for(char *p = strtok(line, " "); p != NULL; p = strtok(NULL, " ")){
				v[pos] = atof(p);
				if(++pos == 4){
					roof_area = (v[0] + v[1]) * v[2];
					covered_area = roof_area * cos(v[3] * conv);
					lot_roof_area += roof_area;
					lot_covered_area += covered_area;
					++roof;
					pos = 0;
				}
			}
		}
		total_roof_area += lot_roof_area *= .5;
		total_covered_area += lot_covered_area *= .5;
		pct_covered = 100 * lot_covered_area / lot_area;
		total_area += lot_area;
		printf("%9.2lf     %10.2lf     %8.2lf%%\n", lot_roof_area, lot_covered_area, pct_covered);
		++lot_count;
	}
	puts("");
	printf("Total surface area of roofs %11.2lf\n", total_roof_area);
	printf("Total area covered by roofs %11.2lf\n", total_covered_area);
	printf("Percentage of total area covered by roofs %7.2lf%%\n", 
			100 * total_covered_area / total_area);
	printf("Average roof surface area per lot %15.2lf\n", total_roof_area / lot_count);
	printf("Average floor space covered per lot %13.2lf\n", total_covered_area / lot_count);

	return 0;
}

