// ===== 簡易カウンター =====

let count = 0;

function increment() {
  count++;
  console.log(`カウントアップ → ${count}`);
}

function decrement() {
  count--;
  console.log(`カウントダウン → ${count}`);
}

function reset() {
  count = 0;
  console.log(`リセット → ${count}`);
}

function showCount() {
  console.log(`現在のカウント：${count}`);
}

// 動作確認
showCount();
increment();
increment();
increment();
decrement();
showCount();
reset();
showCount();
