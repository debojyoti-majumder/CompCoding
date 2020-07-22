package alpha;

// Problem URL: https://leetcode.com/problems/course-schedule/
// Problem ID: 207

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class BasicCourseTaker {
    private Map<Integer,Integer> prereqs;

    private void buildPreReqMap(int[][] reqs) {
        prereqs = new HashMap<Integer, Integer>();
        for(var req : reqs ) prereqs.put(req[0], req[1]);
    }

    private int checkForCourse(int courseId, int threshold) {
        int pathCount = 0;
        Integer currentCourse = courseId;
        Set<Integer> visitedNodes = new HashSet<>();
        visitedNodes.add(currentCourse);

        while( currentCourse != null ) {
            pathCount++;
            currentCourse = prereqs.get(currentCourse);

            if( visitedNodes.contains(currentCourse) ) {
                pathCount = -1;
                break;
            }

            visitedNodes.add(currentCourse);
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
            int retVal = checkForCourse(req[0], coursesLeft);
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
