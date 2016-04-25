//
//  CTECGraph.hpp
//  NodeStuff
//
//  Created by Nemelka, Sydney on 4/25/16.
//  Copyright © 2016 Nemelka, Sydney. All rights reserved.
//

#ifndef CTECGraph_hpp
#define CTECGraph_hpp

#include <set>

namespace CTECData
{
    template <class Type>
    class CTECGraph
    {
    private:
        static const int MAXIMUM = 20;
        bool adjacencyMatrix [MAXIMUM] [MAXIMUM];
        Type labels [MAXIMUM];
        int manyVertices;
    public:
        CTECGraph();
        ~CTECGraph();
        
        void addVertex(const Type& value);
        void addEdge(int source, int target);
        void removeEdge(int source, int target);
        Type& operator [] (int vertex);
        Type operator[] (int vertex) const;
        int size();
        bool isEdge(int source, int target) const;
        std::set<int> neighbors(int vertex) const;
        
    };;
}
#endif /* CTECGraph_hpp */
