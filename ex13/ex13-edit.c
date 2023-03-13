#include <stdio.h>

int main(int argc, char* argv[]){
	for(int j = 1;j < argc;j++){

		int i=0;
		char letter;
		letter = argv[j][i];
		for(i = 0;argv[j][i] != '\0';i++,letter = argv[j][i]){
			//char letter = argv[j][i];

			switch(letter){
				case 'A':
				case 'a':
					printf("%d: 'a'\n",i);
					break;

				case 'E':
				case 'e':
					printf("%d: 'e'\n",i);
					break;

				case 'I':
				case 'i':
					printf("%d: 'i'\n",i);
					break;

				case 'O':
				case 'o':
					printf("%d: 'o'\n",i);
					break;

				case 'U':
				case 'u':
					printf("%d: 'u'\n",i);
					break;

				case 'Y':
				case 'y':
					if(i>2){
						// it's only sometimes y
						printf("%d: 'y'\n", i);
						break;
					}
					//break;

				default:
					printf("%d: %c is not a vowel\n",i,letter);
			}
		}
	}

	return 0;
}
