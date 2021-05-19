# include <iostream>
using namespace std;

struct  nodo {
    char nombre; 
    struct  nodo * siguiente;
    struct  arista * adyacente;
};

struct  arista {
    struct nodo * destino; 
    struct arista * siguiente;
};

typedef  struct  nodo * Tnodo;
typedef  struct  arista * Tarista;
Tnodo p; 

void menu();
void  insertarVertice ();
void  agrega_arista (Tnodo &, Tnodo &, Tarista &);
void  insertarArista ();
void  vaciar_aristas (Tnodo &);
void  eliminarVertice ();
void  eliminarArista ();
void  mostrar_grafo ();
void  mostrar_aristas ();

int  main ( void ){
	p = NULL ;
    int op; 
    do
    {
        menu ();
        cin >> op;
        switch (op)
        {
            case  1 :
                    insertarVertice ();
                    system("pause");
                    break ;
            case  2 : insertarArista ();
            		system("pause");
                    break ;
            case  3 : mostrar_grafo ();
            		system("pause");
                    break ;
            case  4 : mostrar_aristas ();
            		system("pause");
                    break ;
            case  5 : 
            		eliminarVertice ();
            		system("pause");
                    break ;
            case  6 : eliminarArista (); 
            		system("pause");
                    break ;
            default : char respuesta;
					cout<<"\n\tDesea regresar al: \n\t\t**MENU PRINCIPAL** (s/n):  ";
					cin>>respuesta;
					if(respuesta=='s'||respuesta=='S'){
						system("cls");
						main();
					}else{
						system("cls");
						cout<<"\n\n\t\t**GRACIAS POR USAR EL PROGRAMA**"<<endl;
						exit(0);
					}
                    break ;
        }
        cout << endl << endl;
		system ( " cls " );
    } while (op!=6);
    return(0);
}
void menu (){
    cout << "\n\n\tOperaciones de grafos"<<endl;
    cout << "\t1. Insertar Vertice" << endl;
    cout << "\t2. Insertar arista" << endl;
    cout << "\t3. Mostrar grafo" << endl;
    cout << "\t4. Mostrar arista" << endl;
    cout << "\t5. Eliminar Vertice" << endl;
    cout << "\t6. Eliminar arista" << endl;
    cout << "\t7. Salir" << endl;

    cout << "\n\tDigite el numero de la accion que desea realizar: " ;
}
void insertarVertice(){
	Tnodo t, nuevo = new  struct  nodo ;
    cout << "\tIngrese un numero para el nodo: " ;
    cin >> nuevo-> nombre ;
    nuevo-> siguiente = NULL ;
    nuevo-> adyacente = NULL ;

    if (p == NULL ){
        p = nuevo;
    }
    else{
        t = p;
        while (t-> siguiente != NULL )
         {
            t = t-> siguiente ;
          }
        t-> siguiente = nuevo;
    }
}
void  agrega_arista (Tnodo & aux, Tnodo & aux2, Tarista & nuevo){
    Tarista q;
    if (aux-> adyacente == NULL ){
    	aux-> adyacente = nuevo;
        nuevo-> destino = aux2;
    }else{
		q = aux-> adyacente ;
        while (q-> siguiente != NULL )
            q = q-> siguiente ;
        nuevo-> destino = aux2;
        q-> siguiente = nuevo;
    }
}
void  insertarArista (){    
	char ini, fin;
    Tarista nuevo = new  struct  arista;
    Tnodo aux, aux2;
    if(p == NULL ){
        cout << "\tGrafo Vacio " <<endl;
        return ;
    }
    nuevo-> siguiente = NULL ;
    cout <<"\tIngrese el vertice de inicio: " ;
    cin >> ini;
    cout <<"\tIngrese el vertice final: " ;
    cin >> fin;
    aux = p;
    aux2 = p;
    while(aux2!= NULL ){
        if (aux2-> nombre == fin){
            break;
        }
        aux2 = aux2-> siguiente ;
    }
    while (aux!= NULL ){
        if (aux-> nombre == ini)
        {
            agrega_arista (aux, aux2, nuevo);
            return ;
        }

        aux = aux-> siguiente ;
    }
}
void  vaciar_aristas (Tnodo & aux)
{
    Tarista q, r;
    q = aux-> adyacente ;
    while (q-> siguiente != NULL )
    {
        r = q;
        q = q-> siguiente ;
        delete (r);
    }
}
void  eliminarVertice (){
    char var;
    Tnodo aux, hormiga;
    aux = p;
    cout <<"\tELIMINAR UN VERTICE"<<endl;
    if(p == NULL ){
        cout <<"\tGrafo Vacio" <<endl;
        return ;
    }
    cout <<"\tIngrese el vertice a eliminar: " ;
    cin >> var;

    while (aux!= NULL )
    {
        if (aux-> nombre == var)
        {
            if (aux-> adyacente != NULL )
                vaciar_aristas (aux);

            if (aux == p)
            {
                    p = p-> siguiente ;
                    delete (aux);
                    cout <<"\tEliminado Correctamente" <<endl;
                    return ;
            }
            else{
				hormiga-> siguiente = aux-> siguiente ;
                delete (aux);
                cout <<"\tEliminado Correctamente" <<endl;
                return ;
            }
        }
        else
        {
            hormiga = aux;
            aux = aux-> siguiente ;
         }
    }
}
void eliminarArista (){
	char ini, fin;
    Tnodo aux, aux2;
    Tarista q, r;
    cout << "\n\tELIMINAR ARISTA"<<endl;
    cout << "\tIngrese el vertice de inicio: " ;
    cin >> ini;
    cout << "\tIngrese el vertice final: " ;
    cin >> fin;
    aux = p;
    aux2 = p;
    while (aux2!= NULL )
    {
        if (aux2-> nombre == fin)
        {
            break ;
        }
        else
        aux2 = aux2-> siguiente ;
    }
    while (aux!= NULL )
    {
        if (aux-> nombre == ini)
        {
            q = aux-> adyacente ;
            while (q!= NULL )
            {
                if (q-> destino == aux2)
                {
                    if (q == aux-> adyacente )
                        aux-> adyacente = aux-> adyacente -> siguiente ;
                    else
                        r-> siguiente = q-> siguiente ;
                    delete (q);
                    cout << "Arista:  "<<aux-> nombre <<"\nEliminado Correctamente" ;
                    return ;
                }
            }
            r = q;
            q = q-> siguiente ;
        }
        aux = aux-> siguiente ;
    }
}
void  mostrar_grafo ()
{Tnodo ptr;
    Tarista ar;
    ptr = p;
    cout<<"Nodo\t|\tAdyacencia"<<endl;
    while (ptr!= NULL ){
		cout << "   " <<ptr-> nombre << "\t| " ;
        if(ptr-> adyacente != NULL )
        {
            ar = ptr-> adyacente ;
            while (ar!= NULL ){
				cout << "\t" <<ar-> destino -> nombre ;
                ar = ar-> siguiente ;
            }
        }
        ptr = ptr-> siguiente ;
        cout << endl;
    }
}
void  mostrar_aristas ()
{
    Tnodo aux;
    Tarista ar;
    char var;
    cout << "\tMOSTRAR ARISTAS DE VERTICE \n " ;
    cout << "\tIngrese el vertice: " ;
    cin >> var;
    aux = p;
    while (aux!= NULL )
    {
        if (aux-> nombre == var)
        {
            if(aux-> adyacente == NULL ){
				cout << "\tEl nodo no tiene aristas" <<endl;
                return ;
             }
            else
            {
                cout<<"\tNodo\t|\tAdyacencia"<<endl;
                cout << "    " <<aux-> nombre << " | " ;
                ar = aux-> adyacente ;

                while (ar!= NULL )
                {
                    cout <<ar-> destino -> nombre << "  " ;
                    ar = ar-> siguiente ;
                }
                cout << endl;
                return ;
            }
        }
        else
        aux = aux-> siguiente ;
    }
}
