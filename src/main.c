#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct record{
	int hr;
	int mn;
	int se;
	char nm[100];
	int status;
}obj;

int main(){
	while(1){
		system("cls");
		int ch;
		char name[100];
		system("cls");
		system("TITLE Reminder by dev7060 (github.com/dev7060)");
		system("color 03");
		printf("\n\tMenu:\n\t1) Add\n\t2) Delete\n\t3) Enter Run Mode\n\t4) View Entries\n\n\t$ ");
		fflush(stdin);
		scanf("%d", &ch);
		if(ch==1){
			FILE *fp = fopen("data.txt", "a");
			fflush(stdin);
			system("cls");
			printf("\n\tEntry name: ");
			fflush(stdin);
			scanf("%s", &obj.nm);
			printf("\n\tInput time (hh mm ss): ");
			fflush(stdin);
			scanf("%d %d %d", &obj.hr, &obj.mn, &obj.se);
			obj.status = 244;
			fprintf(fp, "%s %d %d %d %d\n", obj.nm, obj.hr, obj.mn, obj.se, obj.status);
			fclose(fp);
			printf("\n\tEntry added successfully!\n\t");
			system("pause");
		}else if(ch==2){
			char name[100];
			FILE *fp = fopen("data.txt", "r");
			FILE *fp2 = fopen("temp.txt", "w");
			system("cls");
			fflush(stdin);
			printf("\n\tEntry name: ");
			scanf("%s", &name);
			int new_st = 245;
			while(fscanf(fp, "%s %d %d %d %d\n", &obj.nm, &obj.hr, &obj.mn, &obj.se, &obj.status)!=EOF){
				if(strcmp(obj.nm, name)==0){
					fprintf(fp2, "%s %d %d %d %d\n", obj.nm, obj.hr, obj.mn, obj.se, new_st);
				}
				else{
					fprintf(fp2, "%s %d %d %d %d\n", obj.nm, obj.hr, obj.mn, obj.se, obj.status);
				}
			}
			fclose(fp);
			fclose(fp2);
			system("del data.txt");
			system("ren temp.txt data.txt");
			printf("\n\tDeletion successful!\n\t");
			system("pause");
		}else if(ch==3){
			while(1){
				FILE *fp = fopen("data.txt", "r");
				while(fscanf(fp, "%s %d %d %d %d\n", &obj.nm, &obj.hr, &obj.mn, &obj.se, &obj.status)!=EOF){
					int hours, minutes, seconds;
					time_t now;
					time(&now);
					struct tm *local = localtime(&now);
    				hours = local->tm_hour;
    				minutes = local->tm_min;
    				seconds = local->tm_sec;
    				system("cls");
    				printf("\n\n\t\t%d:%d:%d\n", hours, minutes, seconds);
    				if(obj.status==244 && obj.hr==hours && obj.mn==minutes && obj.se==seconds){
    					char temp44[100]="START CMD /C \"ECHO ";
    					strcat(temp44, obj.nm);
    					strcat(temp44, " && PAUSE\"");
						system(temp44);
						system("ping 127.0.0.1 -n 5 > nul");		
					}
				}
				fclose(fp);
			}
		}else if(ch==4){
			system("cls");
			FILE *fp = fopen("data.txt", "r");
			while(fscanf(fp, "%s %d %d %d %d\n", &obj.nm, &obj.hr, &obj.mn, &obj.se, &obj.status)!=EOF){
				if(obj.status!=245){
					printf("Name: %s, Time: %d:%d:%d\n", obj.nm, obj.hr, obj.mn, obj.se);	
				}
			}
			system("pause");
			fclose(fp);
		}else{
			printf("\n\tInvalid Choice!\n\t");
			system("pause");
		}
	}
	return 0;
}
