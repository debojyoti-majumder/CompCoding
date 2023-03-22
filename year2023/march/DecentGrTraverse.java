import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

// LEET: 2492
public class Solution {
    class CityConnection {
        private final int   _destination;
        private final int   _weight;
        private boolean     _visited;

        public CityConnection(int dest, int w) {
            _destination = dest;
            _weight = w;
        }

        public void visit() { _visited = true; }
        public boolean isVisited() { return _visited; };

        public int getDestId() { return _destination; }
        public int getWeight() { return _weight; }
    }

    class CityNode {
        private int                     _nodeId;
        private List<CityConnection>    _connectedCities; 
        private Integer                 _minWeight;

        public CityNode(int n) {
            _nodeId = n;
            _connectedCities = new ArrayList<>();
            _minWeight = Integer.MAX_VALUE;
        }

        public void updateMin(int v) {
            if( v < _minWeight ) _minWeight = v;
        }

        public int getMinWight() { return _minWeight; }
        public int getId() { return _nodeId; }

        public void addConnection(CityConnection conn) {
            _connectedCities.add(conn);
        }

        public List<Integer> getUnVisitedNodes() {
            List<Integer> retItems = new ArrayList<>();
            for( var conn : _connectedCities ) {
                if( conn.isVisited() == false ) {
                    conn.visit();
                    retItems.add(conn.getDestId());
                };
            }

            return retItems;
        }

        public int getWeight(int nodeId) {
            for( var conn : _connectedCities ) {
                if( conn.getDestId() == nodeId ) return conn.getWeight();
            }

            // This means it is disconnected
            return 0;
        }
    }

    private Map<Integer, CityNode> _cityMap;

    public int minScore(int n, int[][] roads) {
        _cityMap = new HashMap<>();
        for( int i=0; i<n; i++ ) _cityMap.put(i+1, new CityNode(i+1));
        
        int minScore = 0;

        // Creating of the graph is happening
        for( int i=0; i<roads.length; i++ ) {
            int sourceId = roads[i][0];
            int destId = roads[i][1];
            int distance = roads[i][2];

            CityConnection conn1 = new CityConnection(destId, distance);
            CityConnection conn2 = new CityConnection(sourceId, distance);

            CityNode source = _cityMap.get(sourceId);
            source.addConnection(conn1);
            CityNode dest = _cityMap.get(destId);
            dest.addConnection(conn2);
        }

        Queue<CityNode> visitQueue = new LinkedList<>();
        visitQueue.add(_cityMap.get(1));

        while( !visitQueue.isEmpty() ) {
            // This would remove the elmenemt from the queue;
            CityNode currentNode = visitQueue.poll();

            for( int i : currentNode.getUnVisitedNodes() ) {
                CityNode destNode = _cityMap.get(i);
                int w = currentNode.getWeight(i);

                visitQueue.add(destNode);
                currentNode.updateMin(w);
            }
        }

        // We return the min weight of the target
        return _cityMap.get(n).getMinWight();
    }
}
