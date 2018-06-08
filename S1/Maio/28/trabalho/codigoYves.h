short int laplace[3][3] = {{0, -1, 0},
                              {-1, 4, -1},
                              {0, -1, 0}};



int convoluir(int i, int j, short int laplace[][3], unsigned char **pgm){
	int p, q, temp;
	int element = 0;
	i = i - 1; 
	j = j - 1;
	temp = j;
	for(p = 0; p < 3; p++){
		for(q = 0; q < 3; q++){
	    		element += pgm[i][j] * laplace[p][q];
	    		j++;
		}
		j = temp;
		i++;
	}
	element = (element > 255?255:element);
	element = (element < 0?0:element);
	return element;
}
unsigned char** cat_shadow(unsigned char **m, int linha, int coluna){
	for(int i = 1; i < linha - 1; i++){
		for(int j = 1; j < coluna - 1; j++){
			m[i][j] = convoluir(i, j, laplace, m);
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	return m;
}
