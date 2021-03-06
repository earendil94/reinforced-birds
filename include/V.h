#ifndef __V_H_
#define __V_H_

#include "Observable.h"

class V{

    private:
        std::vector<double> _w;

    public:
        V(std::size_t size);
        auto& get() const {return _w;}
        auto size() const {return _w.size();}
        double& operator[] (std::size_t i);
        
        template<typename T>
        double& operator[] (const Observable<T> &o);
};

template <typename T>
double& V::operator[](const Observable<T> &o){
    return _w[o.index()];
}

template<typename T>
double scalar(V &v, Observable<T> &o){
    
    //Notice that it must be v.size() == o.size(). We will not check for performance reasons
    double res=0;
    for(std::size_t i=0; i<v.size(); ++i){
        res+=v[i]*o[i];
    }

    return res;
}

#endif