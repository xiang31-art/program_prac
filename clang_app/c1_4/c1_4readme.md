#RPG風キャラクター管理ツール

##概要
最大5体のキャラクターどうしを戦わせることができます

##作成関数
###1.キャラ登録
-create_character(Character *c)

###2.ステータス表示(1体)
-show_character()

###3.全キャラ一覧表示
show_all(Character *c, int count)

###4.2体でバトル
-battle()
ダメージ = 攻撃側のattack - 防御側のdefense
（0以下なら1ダメージ）



###5.HP回復
-heal()
