// ===== おみくじ =====

const fortunes = [
  "大吉：最高の一日になるでしょう！",
  "中吉：良いことがありそうです。",
  "小吉：小さな幸せが見つかります。",
  "吉：まずまずの運勢です。",
  "末吉：焦らずいけば好転します。",
  "凶：慎重に過ごしましょう。",
  "大凶：今日はおとなしくしていましょう…。"
];

function drawFortune() {
  const index = Math.floor(Math.random() * fortunes.length);
  return fortunes[index];
}

function showResult(name) {
  const result = drawFortune();
  console.log(`${name}さんの運勢は…`);
  console.log(result);
}

// 動作確認
showResult("太郎");
console.log("---");
showResult("花子");
console.log("---");
showResult("太郎");
