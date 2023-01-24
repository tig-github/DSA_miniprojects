#ifdef DCEL
#define DCEL

#include <utility>


template <typename numberType>
class DoublyConnectedEdgeList {
    public:
        struct Vertex {
            std::pair<numberType, numberType> Coordinates;
            HalfEdge* IncidentEdge;
        }
        struct HalfEdge {
            Vertex* Origin;
            HalfEdge* Twin;
            Face* IncidentFace;
            HalfEdge* Next;
            HalfEdge* Prev;
        }
        struct Face {
            HalfEdge* OuterComponent;
            HalfEdge* InnerComponent;
        };

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

        static DoublyConnectedEdgeList<numberType> computeOverlay(DoublyConnectedEdgeList<numberType> DCEL1,
                                                                  DoublyConnectedEdgeList<numberType> DCEL2);

        void printFaces();
        void printHalfEdges();
        void printVertices();

};









#endif