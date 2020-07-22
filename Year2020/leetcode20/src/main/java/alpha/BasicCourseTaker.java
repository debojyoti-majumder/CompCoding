package alpha;

// Problem URL: https://leetcode.com/problems/course-schedule/
// Problem ID: 207

import java.util.*;

public class BasicCourseTaker {
    private Map<Integer, List<Integer>> prereqs;

    private void buildPreReqMap(int[][] reqs) {
        prereqs = new HashMap<Integer, List<Integer>>();

        for(var req : reqs ) {
            var nd = prereqs.get(req[0]);
            if( nd != null ) nd.add(req[1]);
            else prereqs.put(req[0], new ArrayList<>(req[1]));
        };
    }

    private int checkForCourse(int courseId, int threshold, Set<Integer> visitedNodes) {
        int pathCount = 0;
        Integer currentCourse = courseId;
        visitedNodes.add(currentCourse);

        var decedentsCourses = prereqs.get(currentCourse);
        for( var cr : decedentsCourses ) {
            int val = checkForCourse(cr, threshold - 1,visitedNodes);
            if( val == -1 ) return -1;

            pathCount += val;
        }

        return pathCount;
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        boolean canBeFinished = false;
        int coursesLeft = numCourses;

        if( coursesLeft == 1 ) return true;

        // Building the map
        buildPreReqMap(prerequisites);

        // Going through each test cases
        for(var req : prerequisites ) {
            var visitSet = new HashSet<Integer>();

            int retVal = checkForCourse(req[0], coursesLeft, visitSet);
            if( retVal != -1 ) coursesLeft -= retVal;

            // Basic criteria satisfied
            if( coursesLeft <= 0 ) {
                canBeFinished = true;
                break;
            }
        }

        return canBeFinished;
    }
}
