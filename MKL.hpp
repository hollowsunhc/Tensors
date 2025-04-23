#pragma once

#include "Base.hpp"


#ifndef MKL_Complex8

    #define MKL_Complex8 std::complex<float>

#endif

#ifndef MKL_Complex16

    #define MKL_Complex16 std::complex<double>

#endif

#ifdef TPE_MKL_USE_ILP64

    #ifndef MKL_ILP64

        #define MKL_ILP64

        #pragma message("Tensors/MKL.hpp: Forcing MKL_ILP64 based on CMake definition.")

    #endif

    #ifndef TENSORS_ILP64

        #define TENSORS_ILP64

    #endif
#else

    // If CMake doesn't define TPE_MKL_USE_ILP64, assume LP64
    #ifdef MKL_ILP64

        #undef MKL_ILP64
        
        #pragma message("Tensors/MKL.hpp: Undefining MKL_ILP64 for LP64.")

    #endif

     #ifdef TENSORS_ILP64

        #undef TENSORS_ILP64

     #endif
#endif
    
#include <mkl.h>

namespace Tensors
{
    constexpr bool AppleAccelerateQ = false;
    constexpr bool OpenBLASQ        = false;
    constexpr bool MKLQ             = true;
    
    namespace BLAS
    {
        using Int           = MKL_INT;
        using Bool          = bool;
        using ComplexFloat  = MKL_Complex8;
        using ComplexDouble = MKL_Complex16;
    }
    
    namespace LAPACK
    {
        using Int           = MKL_INT;
        using Bool          = bool;
        using ComplexFloat  = MKL_Complex8;
        using ComplexDouble = MKL_Complex16;
    }
}

#include "src/BLAS_Wrappers.hpp"
#include "src/LAPACK_Wrappers.hpp"
