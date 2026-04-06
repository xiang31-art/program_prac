// ===== 簡易カウンター =====

let count = 0;  //グローバル変数によってどの関数でも変更可

function increment() {
    count++;    //インクリメント処理
    console.log(`カウントアップ → ${count}`);   //結果表示
}

function decrement() {
    count--;    //デクリメント処理
    console.log(`カウントダウン → ${count}`);   //結果表示
}

function reset() {
    count = 0;  //0にリセット
    console.log(`リセット → ${count}`);         //結果表示
}

function showCount() {
    console.log(`現在のカウント：${count}`);    //現在の状況表示
}

//動作チェック
showCount();
increment();
increment();
decrement();
increment();
reset();
showCount();