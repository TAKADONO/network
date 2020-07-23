makefileはまだ作れてません

実行方法
gcc -c BA.c
gcc -c closeness_centrality.c
gcc -c MtoL.c
gcc -c test.c
gcc test.o BA.o closeness_centrality.o MtoL.o  -o test
./test


BA.c：バラバーシモデルの生成
MtoL.c：隣接行列からリスト絵の変換
closeness_centrality.c：今のところは各頂点間の最短距離を調べるもの
test.c：main文