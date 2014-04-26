#include <nd_product.h>

#include <pthread.h>
#include <iostream>
#include <unistd.h>

NdProduct::NdProduct()
{
    this->isDebug = false;
}

NdProduct::NdProduct(bool isDebug)
{
    this->isDebug = isDebug;
}

NdProduct::~NdProduct()
{
    /* dynamic extension */
    delete [] this->vectorA;
    delete [] this->vectorB;
    delete [] this->results;
}

int NdProduct::dotProduct(vector<int>& a, vector<int>& b) throw ()
{
    if(this->isDebug)
        cout << "[NdProduct][doProduct] size A [" << a.size() << "], size B [" << b.size() << "]" << endl;
    if(a.size() != b.size())
        throw invalid_argument("A size is different from B");
    vector<int>::iterator itrA;
    vector<int>::iterator itrB;
    this->vectorA = new int[a.size()];
    this->vectorB = new int[a.size()];
    this->results = new int[a.size()];
    int index = 0;
    list<pthread_t> threads;
    for(itrA = a.begin(), itrB = b.begin(); itrA != a.end(), itrB != b.end(); itrA++, itrB++) {
        vectorA[index] = *itrA;
        vectorB[index] = *itrB;
        thread_args args;
        args.index = index;
        args.ndProd = this;
        pthread_t thread;
        int retCode = pthread_create(&thread, NULL, handler, &args);
        threads.push_back(thread);
        if(this->isDebug)
            cout << "[NdProduct][doProduct] thread [" << index << "] correctly detached [" << retCode << "]" << endl;
        index += 1;
        usleep(1);
    }

    list<pthread_t>::iterator itr;
    for(itr = threads.begin(); itr != threads.end(); itr++) {
        pthread_join(*itr, NULL);
    }
    if(this->isDebug)
        cout << "threads correctly joined";
    int sum = 0;
    for(unsigned int i = 0; i < a.size(); i++) {
        sum += this->results[i];
    }

    return sum;
}

void* NdProduct::handler(void* param)
{
    thread_args* args = reinterpret_cast<thread_args*>(param);
    if(args->ndProd->isDebug)
        cout << "[NdProduct][handler] thread [" << args->index << "]" << " elements ["<< args->ndProd->vectorA[args->index] << ", "<< args->ndProd->vectorB[args->index] <<"]" << endl;
    args->ndProd->results[args->index] = args->ndProd->vectorA[args->index]*args->ndProd->vectorB[args->index];
    if(args->ndProd->isDebug)
        cout << "[NdProduct][handler] thread [" << args->index << "]" << " partial ["<< args->ndProd->results[args->index] <<"]" << endl;

    return 0;
}
