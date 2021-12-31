#include "computation.h"

#include <math.h>
#include "DTDoubleArrayOperators.h"
#include "DTUtilities.h"

DTImage Computation(const DTImage &input,double weight)
{
    DTImageChannel channel = input(0);
    channel = ConvertToDouble(channel);
    DTDoubleArray first = channel.DoubleArray();

    channel = input(1);
    channel = ConvertToDouble(channel);
    DTDoubleArray second = channel.DoubleArray();
    
    DTDoubleArray result = first*weight + second*(1-weight);
    
    return DTImage(input.Grid(),result,"combined");
}
