/**
 * @file nd_product.h
 *
 * N-dimensional Product.
 *
 * @brief
 *
 * @author Paolo Maresca <plo.maresca@gmail.com>
 * @version 0.1
 */
// $Log$

#ifndef _ND_PRODUCT_H
#define _ND_PRODUCT_H

#include <stdexcept>
#include <vector>
#include <list>

using namespace std;

class NdProduct
{
    public:
        /**
         * Default Constructor.
         */
        NdProduct();
        /**
         * Constructor with 1 argument.
         */
        NdProduct(bool isDebug);
        /**
         * Default Distructor.
         */
        ~NdProduct();
        /**
         * Calculate the dot product between two n-dimensional arrays.
         *
         * @param   a   N-dimensional array of integers
         * @param   b   N-dimensional arrat of integers
         */
        int dotProduct(vector<int>& a, vector<int>& b) throw ();

    protected:
        /**
         * Thread Handler. This functionality represents an hook called by the Thread to execute a
         * specific behaviour .
         *
         * @param[in] Pointer to void accepting any kind of parameter type
         *
         */
        static void* handler(void* param);

    private:
        bool isDebug;
        int* vectorA;
        int* vectorB;
        int* results;
};

/**
 * Thread Arguments. Support data structure to pass multiple arguments to the threads.
 */
typedef struct {
    int index;
    NdProduct* ndProd;
} thread_args;

#endif  /* _ND_PRODUCT_H */
