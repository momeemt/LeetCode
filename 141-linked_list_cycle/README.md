# 1回目
- 既に訪れたポインタを配列に格納しておいて、存在するかチェックすれば良いと思った
- ノード数Nは[0, 10^4]なので、時間計算量がΘ(N^2)でも間に合いそう
- std::findについて調べた（https://cpprefjp.github.io/reference/algorithm/find.html ）
- フロイドの循環検出アルゴリズムについて知ったので、そちらでも書いた（https://scrapbox.io/mutsuha-asada/Floyd's_cycle-finding_algorithm ）

# 2回目
- 1回目よりスムーズに実装できた
- グラフの循環検出なので`visited`でも意図が伝わりそうなので変えた

# 3回目
- 一度2回目と同じ実装をして動くのを確かめてから、setの所属判定は時間計算量がＯ(logN)だったことを思い出して書き直した
- set::insertについて調べた（https://cpprefjp.github.io/reference/set/set/insert.html ）
- 重複して追加した際に既に追加されていた要素のイテレータと、既に追加されていたかどうかを示す真偽値を返すことを知り、時間計算量がよくなりそうだったのでこれを使った

