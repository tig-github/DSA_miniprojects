#ifdef GeometricPrimitives
#define GeometricPrimitives


template <typename numberType>
struct Line { // Ax + By = C
    numberType A;
    numberType B;
    numberType C;
};

// creates a standard form linear equation given a line
template <typename num>
Line<numberType> generateLine(num x1, num x2, num y1, num y2){
    
}


// computes the intersection of 2 lines (x1,y1);(x2,y2) and returns -1 if parallel
template <typename num>
num computeLineIntersection(num x1, num x2, num y1, num y2){


}



#endif