from copy import copy
N = int(input())
events = [input().split() for _ in range(2*N)]
event_time = [int(a[1]) for a in events]

contest_props = []
contest_event = []
contest_time = []
# event_contest = []
total_props = 0
remaining_props = 0
prop_time = []
recent_props = []
contest_recent_props = []
for i in range(2*N):
    if events[i][0] == '+':
        prop_time.append(event_time[i])
        recent_props.append(total_props)
        total_props += 1
        remaining_props += 1
    else:
        contest_props.append(remaining_props)
        remaining_props -= 1

        contest_recent_props.append(copy(recent_props))
        recent_props = []
        # event_contest[i] = len(contest_event)
        contest_event.append(i)
        contest_time.append(event_time[i])

ev = [float(0)]*N
props_ev = [float(0)]*N
for contest in range(N-1, -1, -1):
    if contest != N-1:
        ev[contest] = (1-1/contest_props[contest]) * (contest_time[contest+1] - contest_time[contest] + ev[contest+1])
    for prop in contest_recent_props[contest]:
        props_ev[prop] = ev[contest] + (contest_time[contest] - prop_time[prop])

print(*props_ev, sep='\n')