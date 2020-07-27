import sys


N = int( sys.stdin.readline() )

S = []
for i in range( N ):
    S.append( int( sys.stdin.readline() ) )
S.append( 0 )

tot = 0
for i in range( N ):
    tot += S[i]

if N == 1:
    print( S[0] )
elif N == 2:
    print( S[0] + S[1] )
else:
    for i in range( N ):
        if i > 1:
            S[i+1] += min( S[i-1], S[i-2] )
    R = tot - S[N]
    print( R )
