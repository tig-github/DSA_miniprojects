#ifdef DCEL
#define DCEL

#include <utility>
#include <vector>
#include "GeometricPrimitives.h"

template <typename numberType>
class DoublyConnectedEdgeList {
    public:
        template <typename T>
        struct Vertex {
            std::pair<numberType, numberType> Coordinates;
            HalfEdge* IncidentEdge;
            T Data;
        }

        template <typename T>
        struct HalfEdge {
            Vertex* Origin;
            HalfEdge* Twin;
            Face* IncidentFace;
            HalfEdge* Next;
            HalfEdge* Prev;
            T Data;
        }

        template <typename T>
        struct Face {
            HalfEdge* OuterComponent;
            HalfEdge* InnerComponent;
            T Data;
        };

        std::vector<Vertex*> VertexRecord;
        std::vector<Face*> FaceRecord;
        std::vector<HalfEdge*> HalfEdgeRecord;
    
        DoublyConnectedEdgeList();
        DoublyConnectedEdgeList(const DoublyConnectedEdgeList<numberType> &DCEL);
        ~DoublyConnectedEdgeList() noexcept;
        DoublyConnectedEdgeList<numberType> operator=(const DoublyConnectedEdgeList<numberType> &DCEL);
        DoublyConnectedEdgeList(DoublyConnectedEdgeList<T> &&DCEL) noexcept;
        DoublyConnectedEdgeList<numberType> operator=(const DoublyConnectedEdgeList<numberType> &&DCEL) noexcept;

        int numFaces();
        int numVertices();
        int numHalfEdges();
        int numEdges();

        void addFace();
        void addVertex();
        void addHalfEdge();
        
        void removeFace();
        void removeVertex();
        void removeHalfEdge();

        static DoublyConnectedEdgeList<numberType> computeOverlay(DoublyConnectedEdgeList<numberType> DCEL1,
                                                                  DoublyConnectedEdgeList<numberType> DCEL2);
        static DoublyConnectedEdgeList<numberType> triangulate(DoublyConnectedEdgeList<numberType> DCEL);

        void printFaces();
        void printHalfEdges();
        void printVertices();

        private:
        // geometric privates
        static DoublyConnectedEdgeList<numberType> makeMonotone(DoublyConnectedEdgeList<numberType> DCEL);
        // helper functions
};


template typename<T>
DoublyConnectedEdgeList<numberType>::DoublyConnectedEdgeList(){
    // new instance of DCEL created
}


template typename<T>
DoublyConnectedEdgeList<numberType>::DoublyConnectedEdgeList(DoublyConnectedEdgeList<numberType>& DCEL){

}


#endif