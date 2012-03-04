#include <cstdio>
#include <cstring>

int ec, event[50][3];

bool simulate(double tank){
	double fuel = tank, kml = 1e10;
	int at = 0, leaking = 0;
	for(int i = 0; i < ec; ++i){
		fuel -= (event[i][0] - at) * kml;
		fuel -= leaking * (event[i][0] - at);
		if(fuel < 0) return false;
		switch(event[i][1]){
			case 'C': kml = event[i][2] / 100.0; break; // Consumption change
			case 'E': break; // End
			case 'F': fuel = tank; break; // Gas Station - Fill tank
			case 'L': ++leaking; break; // Leak
			case 'M': leaking = 0; break; // Mechanic - Fix leak
		}
		at = event[i][0];
	}
	return true;
}
int main(void){
	int kml; char desc[32];
	while(scanf("%d %[A-Za-z ] %d", &event[0][0], desc, &event[0][2]) == 3 && event[0][2]){
		event[0][1] = 'C'; // Consumption change
		for(ec = 1; strcmp(desc, "Goal"); ++ec){
			scanf("%d %[A-Za-z ]", &event[ec][0], desc);
			if(*desc == 'G'){ // Goal or Gas Station
				if(*(desc + 1) == 'o') event[ec][1] = 'E'; // End
				else event[ec][1] = 'F'; // Fuel
			} else if(*desc == 'F'){
				event[ec][1] = 'C'; // Consumption change
				scanf("%d", &event[ec][2]);
			} else event[ec][1] = *desc; // Leak or Mechanic
		}
		double high, low, mid;
		for(kml = low = 0, high = 1e8; kml < 38; ++kml){
			mid = (low + high) * .5;
			if(simulate(mid)) high = mid;
			else low = mid;
		}
		printf("%.3lf\n", low);
	}
	return 0;
}

