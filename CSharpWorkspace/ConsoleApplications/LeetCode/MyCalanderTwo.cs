using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    class MeetingRange
    {
        public int StartPoint;
        public int EndPoint;
        public int OverlapCount;

        public MeetingRange(int s, int d)
        {
            StartPoint = s;
            EndPoint = d;
            OverlapCount = 0;
        }

        public bool IsOverLapping(MeetingRange r)
        {
            if (r.StartPoint >= EndPoint && r.StartPoint < EndPoint)
                return true;
            else
                return false;
        }
    }

    public class MyCalendarTwo
    {
        List<MeetingRange> _meetingRanges;

        public MyCalendarTwo()
        {
            _meetingRanges = new List<MeetingRange>();
        }

        public bool Book(int start, int end)
        {
            MeetingRange r = new MeetingRange(start, end);
            bool conflictFound = false;

            if (_meetingRanges.Count == 0)
            {
                _meetingRanges.Add(r);
                return true;
            }

            foreach (MeetingRange range in _meetingRanges)
            {
                if (range.IsOverLapping(r))
                {
                    conflictFound = true;
                    break;
                }
            }

            if (false == conflictFound)
                _meetingRanges.Add(r);

            return false;
        }
    }
}
