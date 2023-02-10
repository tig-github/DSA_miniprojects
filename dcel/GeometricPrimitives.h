#ifdef GeometricPrimitives
#define GeometricPrimitives

#define MAX_INT 2147483647

template <typename num>
struct Line { // Ax + By = C
    num A;
    num B;
    num C;
    std::pair<num, num> upperEndpoint = MAX_INT; // if uninitialized, line is not a segment
    std::pair<num, num> lowerEndpoint = MAX_INT;
};


// handles divide by zero errors returning -1, otherwise returns quotient
template <typename num>
num safeDivide(num a, num b){
    if (b == 0){
        return -1;
    }
    return a / b;
}

// creates a standard form linear equation given a line
template <typename num>
Line<num> generateLine(num x1, num x2, num y1, num y2, bool isSegment = true){
    num m = (y2 - y1) / (x2 - x1); // will this overflow?
    num b = y1 - m*x; // this gives slope intercept form

    num A = m;
    num B = 1;
    num C = b; //no need to alter coefficients for computations

    Line<num> newLine;
    if (isSegment){
        newLine = {A, B, C, std::pair<x1,y1>, std::pair<x2,y2>};
    }
    else {
        newLine = {A, B, C, MAX_INT, MAX_INT}
    }
    return newLine;
}


// computes the intersection of 2 lines (x1,y1);(x2,y2) and returns -1 if parallel
template <typename num>
std::pair<num, num> computeLineIntersection(Line1<num>, Line2<num>){
    num a1 = Line1.A; num a2 = Line2.A;
    num b1 = Line1.B; num b2 = Line2.B;
    num c1 = Line1.C; num c2 = Line2.C;

    num x = safeDivide((b1*c2 - b2*c1), (a1*b2 - a2*b1));
    num y = safeDivide((a2*c1 - a1*c2), (a1*b2 - a2*b1));
    if (x == -1 || y == -1){ return std::make_pair(-1, -1); }
    return std::make_pair(x, y);
}



#endif