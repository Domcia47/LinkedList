#include <iostream>
#include "LinkedList.hpp"


int main(){
    std::ios_base::sync_with_stdio(false);
    
    int n;//zmienna przechowująca liczbę operacji
    int x,y;
    std::string s;//zmienna do przechowywania symbolu operacji
    std::cin>>n;//wczytaj liczbę operacji
    
    //sprawdzenie czy wczytana wartość spełnia warunki zadania
    if(n>1000000){
        std::cout<<"Argument out of range."<<std::endl;
        return 1;
    }
    List list;//utwórz liste
    

    for(int i =0; i<n;i++){
        std::cin>>s;//wczytaj znak odpowiadający operacji
        
        if(s=="F"){
            std::cin >> x;
            list.push_front(x);
        }
        if(s=="B"){
            std::cin >> x;
            list.push_back(x);
        }
        if(s=="f"){
            if(list.empty()) std::cout << "EMPTY"<<std::endl;
            else std::cout<<list.pop_front()<<std::endl;
        }
        if(s=="b"){
            if(list.empty()) std::cout << "EMPTY"<<std::endl;
            else std::cout<<list.pop_back()<<std::endl;
        }
        if(s=="R"){
            std::cin>>x;
            std::cin>>y;
            int position;
            position= list.find(x);
            if(position==-1) std::cout << "FALSE"<<std::endl;
            else{
                list.erase(position);
                list.insert(position,y);
                std::cout<<"TRUE"<<std::endl;
            }
        }
        if(s=="S"){
            std::cout<<list.size_()<<std::endl;
        }
     
    }
}