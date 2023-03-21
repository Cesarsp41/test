int down[3][3] = {{0,0,0,},{0,0,0,},{0,0,0}};
int front[3][3] = {{0,0,0,},{0,0,0,},{0,0,0}};
int right[3][3] = {{0,0,0,},{0,0,0,},{0,0,0}};
int left[3][3] = {{0,0,0,},{0,0,0,},{0,0,0}};
int back[3][3] = {{0,0,0,},{0,0,0,},{0,0,0}};
int up[3][3] = {{0,0,0,},{0,0,0,},{0,0,0}};

void R(); //Done
void RP(); //Done
void L(); //Done
void LP(); //Done
void FR(); //Done
void FP(); //Done
void B(); //Done
void BP(); //Done
void U(); //Done
void UP(); //Done
void D(); //Done
void DP(); //Done

void setup()
{
	
}
void loop()
{
	// Do nothing here...
}

//Funciones
void R()
{
    //Array Auxiliar
    int *aux = malloc(3*sizeof(int));
    int *aux2 = malloc(3*sizeof(int));
    int *aux3 = malloc(3*sizeof(int));
    int *aux4 = malloc(3*sizeof(int));

    //Movimiento Lineal de caras
    for (int i = 0; i < 3; i++)
    {
        aux[i] = front[i][2]; // Aux Toma valor de Front (A)
        aux2[i] = up[i][2]; // Aux2 Toma valor de Up (B)
        front[i][2] = down[i][2]; // Front (A) toma el valor de Down (D)
        up[i][2] = aux[i]; // Up (B) toma el valor de Front (A (Aux))
        aux[i] = back[i][0]; //Aux toma el valor de Back(C)
    }

    for (int i = 0; i < 3; i++)
    {
        back[i][0] = aux2[2-i]; //Back (C) el valor de Up(B(Aux2))
        down[i][2] = aux[2-i]; //Down(D) toma el valor de Back(C (aux))
    }

    //Movimiento circular de cara afectada
    for (int i = 0; i < 3; i++)
    {
        aux[i] = right[0][i];
        aux2[i] = right[i][2];
        aux3[i] = right[2][i]; ////Guarda la información de la cara afectada para girarla sobre su propio eje
        aux4[i] = right[i][0];
    }

    for (int i = 0; i < 3; i++)
    {
        right[i][2] = aux[i];
        right[2][i] = aux2[2-i];
        right[i][0] = aux3[i];
        right[0][i] = aux4[2-i];
    }

    free(aux);
    free(aux2);
    free(aux3);
    free(aux4);
}

void RP()
{
    //Array Auxiliar
    int *aux = malloc(3*sizeof(int));
    int *aux2 = malloc(3*sizeof(int));
    int *aux3 = malloc(3*sizeof(int));
    int *aux4 = malloc(3*sizeof(int));

    //Movimiento lineal
    for (int i = 0; i < 3; i++)
    {
        aux[i] = front[i][2];
        aux2[i] = down[i][2];
        aux3[i] = back[i][0];
        aux4[i] = up[i][2];
        down[i][2] = aux[i];
        front[i][2] = aux4[i];
    }

    for (int i = 0; i < 3; i++)
    {
        back[i][0] = aux2[2-i];
        up[i][2] = aux3[2-i];
    }

    //Movimiento Circular
    for (int i = 0; i < 3; i++)
    {
        aux[i] = right[0][i];
        aux2[i] = right[i][0];
        aux3[i] = right[2][i];
        aux4[i] = right[i][2];
    }

    for (int i = 0; i < 3; i++)
    {
        right[0][i] = aux4[i];
        right[i][0] = aux[2-i];
        right[2][i] = aux2[i];
        right[i][2] = aux3[2-i];
    }

    //Liberar memoria
    free(aux);
    free(aux2);
    free(aux3);
    free(aux4);
}

void L()
{
    //Array Auxiliar
    int *aux = malloc(3*sizeof(int));
    int *aux2 = malloc(3*sizeof(int));
    int *aux3 = malloc(3*sizeof(int));
    int *aux4 = malloc(3*sizeof(int));

    //Movimiento lineal
    for (int i = 0; i < 3; i++)
    {
        aux[i] = front[i][0];
        aux2[i] = down[i][0];
        aux3[i] = back[i][2];
        aux4[i] = up[i][0];
        down[i][0] = aux[i];
        front[i][0] = aux4[i];
    }

    for (int i = 0; i < 3; i++)
    {
        back[i][2] = aux2[2-i];
        up[i][0] = aux3[2-i];
    }

    //Movimiento Circular
    for (int i = 0; i < 3; i++)
    {
        aux[i] = left[0][i];
        aux2[i] = left[i][2];
        aux3[i] = left[2][i];
        aux4[i] = left[i][0];
    }

    for (int i = 0; i < 3; i++)
    {
        left[0][i] = aux4[2-i];
        left[i][2] = aux[i];
        left[2][i] = aux2[2-i];
        left[i][0] = aux3[i];
    }

    //Liberar memoria
    free(aux);
    free(aux2);
    free(aux3);
    free(aux4);
}

void LP()
{
    //Array Auxiliar
    int *aux = malloc(3*sizeof(int));
    int *aux2 = malloc(3*sizeof(int));
    int *aux3 = malloc(3*sizeof(int));
    int *aux4 = malloc(3*sizeof(int));

    //Movimiento Lineal
    for (int i = 0; i < 3; i++)
    {
        aux[i] = front[i][0];
        aux2[i] = up[i][0];
        aux3[i] = back[i][2];
        aux4[i] = down[i][0];
        front[i][0] = aux4[i];
        up[i][0] = aux[i];
    }

    for (int i = 0; i < 3; i++)
    {
        back[i][2] = aux2[2-i];
        down[i][0] = aux3[2-i];
    }

    //Movimiento circuilar
    for (int i = 0; i < 3; i++)
    {
        aux[i] = left[0][i];
        aux2[i] = left[i][0];
        aux3[i] = left[2][i];
        aux4[i] =  left[i][2];
    }

    for (int i = 0; i < 3; i++)
    {
        left[0][i] = aux4[i];
        left[i][0] = aux[2-i];
        left[2][i] = aux2[i];
        left[i][2] = aux3[2-i];
    }

    //Liberar memoria
    free(aux);
    free(aux2);
    free(aux3);
    free(aux4);

}

void Fr()
{
    //Array Auxiliar
    int *aux = malloc(3*sizeof(int));
    int *aux2 = malloc(3*sizeof(int));
    int *aux3 = malloc(3*sizeof(int));
    int *aux4 = malloc(3*sizeof(int));

    //Movimiento Lineal
    for (int i = 0; i < 3; i++)
    {
        aux[i] = right[i][0];
        aux2[i] = down[0][i];
        aux3[i] = left[i][2];
        aux4[i] = up[2][i];
        right[i][0] = aux4[i];
        left[i][2] = aux2[i];
    }

    for (int i = 0; i < 3; i++)
    {
        down[0][i] = aux[2-i];
        up[2][i] = aux3[2-i];
    }

    //Movimiento circular
    for (int i = 0; i < 3; i++)
    {
        aux[i] = front[0][i];
        aux2[i] = front[i][2];
        aux3[i] = front[2][i];
        aux4[i] = front[i][0];
    }

    for (int i = 0; i < 3; i++)
    {
        front[0][i] = aux4[2-i];
        front[i][2] = aux[i];
        front[2][i] = aux2[2-i];
        front[i][0] = aux3[i];
    }

    //Liberar memoria
    free(aux);
    free(aux2);
    free(aux3);
    free(aux4);

}

void FP()
{
    //Array Auxiliar
    int *aux = malloc(3*sizeof(int));
    int *aux2 = malloc(3*sizeof(int));
    int *aux3 = malloc(3*sizeof(int));
    int *aux4 = malloc(3*sizeof(int));

    //Movimiento Lineal
    for (int i = 0; i < 3; i++)
    {
        aux[i] = left[i][2];
        aux2[i] = down[0][i];
        aux3[i] = right[i][0];
        aux4[i] = up[2][i];
        down[0][i] = aux[i];
        up[2][i] = aux3[i];
    }

    for (int i = 0; i < 3; i++)
    {
        left[i][2] = aux4[2-i];
        right[i][0] = aux2[2-i];
    }

    //Movimiento circular
    for (int i = 0; i < 3; i++)
    {
        aux[i] = front[0][i];
        aux2[i] = front[i][0];
        aux3[i] = front[2][i];
        aux4[i] = front[i][2];
    }

    for (int i = 0; i < 3; i++)
    {
        front[0][i] = aux4[i];
        front[i][0] = aux[2-i];
        front[2][i] = aux2[i];
        front[i][2] = aux3[2-i];
    }

    //Liberar memoria
    free(aux);
    free(aux2);
    free(aux3);
    free(aux4);

}

void B()
{
    //Array Auxiliar
    int *aux = malloc(3*sizeof(int));
    int *aux2 = malloc(3*sizeof(int));
    int *aux3 = malloc(3*sizeof(int));
    int *aux4 = malloc(3*sizeof(int));

    //Movimiento Lineal
    for (int i = 0; i < 3; i++)
    {
        aux[i] = left[i][0];
        aux2[i] = down[2][i];
        aux3[i] = right[i][2];
        aux4[i] = up[0][i];
        down[2][i] = aux[i];
        up[0][i] = aux3[i];
    }

    for (int i = 0; i < 3; i++)
    {
        left[i][0] = aux4[2-i];
        right[i][2] = aux2[2-i];
    }

    //Movimiento circular
    for (int i = 0; i < 3; i++)
    {
        aux[i] = back[0][i];
        aux2[i] = back[i][2];
        aux3[i] = back[2][i];
        aux4[i] = back[i][0];
    }

    for (int i = 0; i < 3; i++)
    {
        back[0][i] = aux4[2-i];
        back[i][2] = aux[i];
        back[2][i] = aux2[2-i];
        back[i][0] = aux3[i];
    }

    //Liberar memoria
    free(aux);
    free(aux2);
    free(aux3);
    free(aux4);
}

void BP()
{
    //Array Auxiliar
    int *aux = malloc(3*sizeof(int));
    int *aux2 = malloc(3*sizeof(int));
    int *aux3 = malloc(3*sizeof(int));
    int *aux4 = malloc(3*sizeof(int));

    //Movimiento lineal
    for (int i = 0; i < 3; i++)
    {
        aux[i] = right[i][2];
        aux2[i] = down[2][i];
        aux3[i] = left[i][0];
        aux4[i] = up[0][i];
        right[i][2] = aux4[i];
        left[i][0] = aux2[i];
    }

    for (int i = 0; i < 3; i++)
    {
        down[2][i] = aux[2-i];
        up[0][i] = aux3[2-i];
    }

    //Movimiento circular
    for (int i = 0; i < 3; i++)
    {
        aux[i] = back[0][i];
        aux2[i] = back[i][0];
        aux3[i] = back[2][i];
        aux4[i] = back[i][2];
    }

    for (int i = 0; i < 3; i++)
    {
        back[0][i] = aux4[i];
        back[i][0] = aux[2-i];
        back[2][i] = aux2[i];
        back[i][2] = aux3[2-i];
    }

    //Liberar memoria
    free(aux);
    free(aux2);
    free(aux3);
    free(aux4);
}

void U()
{
    //Array Auxiliar
    int *aux = malloc(3*sizeof(int));
    int *aux2 = malloc(3*sizeof(int));
    int *aux3 = malloc(3*sizeof(int));
    int *aux4 = malloc(3*sizeof(int));

    //Movimiento lineal
    for (int i = 0; i < 3; i++)
    {
        aux[i] = front[0][i];
        aux2[i] = left[0][i];
        aux3[i] = back[0][i];
        aux4[i] = right[0][i];
        front[0][i] = aux4[i];
        left[0][i] = aux[i];
        back[0][i] = aux2[i];
        right[0][i] = aux3[i];
    }

    //Movimiento circular
    for (int i = 0; i < 3; i++)
    {
        aux[i] = up[0][i];
        aux2[i] = up[i][2];
        aux3[i] = up[2][i];
        aux4[i] = up[i][0];
    }

    for (int i = 0; i < 3; i++)
    {
        up[0][i] = aux4[2-i];
        up[i][2] = aux[i];
        up[2][i] = aux2[2-i];
        up[i][0] = aux3[i];
    }
    //Liberar memoria
    free(aux);
    free(aux2);
    free(aux3);
    free(aux4);
}

void UP()
{
    //Array Auxiliar
    int *aux = malloc(3*sizeof(int));
    int *aux2 = malloc(3*sizeof(int));
    int *aux3 = malloc(3*sizeof(int));
    int *aux4 = malloc(3*sizeof(int));

    //Movimiento lineal
    for (int i = 0; i < 3; i++)
    {
        aux[i] = front[0][i];
        aux2[i] = right[0][i];
        aux3[i] = back[0][i];
        aux4[i] = left[0][i];
        front[0][i] = aux4[i];
        right[0][i] = aux[i];
        back[0][i] = aux2[i];
        left[0][i] = aux3[i];
    }

    //Movimiento circular
    for (int i = 0; i < 3; i++)
    {
        aux[i] = up[0][i];
        aux2[i] = up[i][0];
        aux3[i] = up[2][i];
        aux4[i] = up[i][2];
    }

    for (int i = 0; i < 3; i++)
    {
        up[0][i] = aux4[i];
        up[i][0] = aux[2-i];
        up[2][i] = aux2[i];
        up[i][2] = aux3[2-i];
    }

    //Liberar memoria
    free(aux);
    free(aux2);
    free(aux3);
    free(aux4);
}

void D()
{
    //Array Auxiliar
    int *aux = malloc(3*sizeof(int));
    int *aux2 = malloc(3*sizeof(int));
    int *aux3 = malloc(3*sizeof(int));
    int *aux4 = malloc(3*sizeof(int));

    //Movimiento lineal
    for (int i = 0; i < 3; i++)
    {
        aux[i] = front[2][i];
        aux2[i] = right[2][i];
        aux3[i] = back[2][i];
        aux4[i] = left[2][i];
        front[2][i] = aux4[i];
        right[2][i] = aux[i];
        back[2][i] = aux2[i];
        left[2][i] = aux3[i];
    }

    //Movimiento circular
    for (int i = 0; i < 3; i++)
    {
        aux[i] = down[0][i];
        aux2[i] = down[i][2];
        aux3[i] = down[2][i];
        aux4[i] = down[i][0];
    }

    for (int i = 0; i < 3; i++)
    {
        down[0][i] = aux4[2-i];
        down[i][2] = aux[i];
        down[2][i] = aux2[2-i];
        down[i][0] = aux3[i];
    }

    //Liberar memoria
    free(aux);
    free(aux2);
    free(aux3);
    free(aux4);
}

void DP()
{
    //Array Auxiliar
    int *aux = malloc(3*sizeof(int));
    int *aux2 = malloc(3*sizeof(int));
    int *aux3 = malloc(3*sizeof(int));
    int *aux4 = malloc(3*sizeof(int));

    //Movimiento lineal
    for (int i = 0; i < 3; i++)
    {
        aux[i] = front[2][i];
        aux2[i] = right[2][i];
        aux3[i] = back[2][i];
        aux4[i] = left[2][i];
        front[2][i] = aux4[i];
        right[2][i] = aux[i];
        back[2][i] = aux2[i];
        left[2][i] = aux3[i];
    }

    //Movimiento circular
    for (int i = 0; i < 3; i++)
    {
        aux[i] = down[0][i];
        aux2[i] = down[i][0];
        aux3[i] = down[2][i];
        aux4[i] = down[i][2];
    }

    for (int i = 0; i < 3; i++)
    {
        down[0][i] = aux4[i];
        down[i][0] = aux[2-i];
        down[2][i] = aux2[i];
        down[i][2] = aux3[2-i];
    }

    //Liberar memoria
    free(aux);
    free(aux2);
    free(aux3);
    free(aux4);
}
