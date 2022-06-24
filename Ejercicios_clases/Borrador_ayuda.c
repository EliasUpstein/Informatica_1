int i = 0, j=1;
while( i < strlen(s) + strlen(t)) {
    t[i] = s[i- (int) strlen(t)];
    i++; j++;  //Copia sobreescribiendo el \0 de t (en strlen(t))
}