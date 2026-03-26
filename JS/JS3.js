// ===== じゃんけんゲーム =====

const hands = ["グー", "チョキ", "パー"];

function getComputerHand() {
  const index = Math.floor(Math.random() * hands.length);
  return hands[index];
}

function judge(player, computer) {
  if (player === computer) {
    return "あいこ";
  }
  if (
    (player === "グー" && computer === "チョキ") ||
    (player === "チョキ" && computer === "パー") ||
    (player === "パー" && computer === "グー")
  ) {
    return "あなたの勝ち！";
  }
  return "あなたの負け…";
}

function play(playerHand) {
  const computerHand = getComputerHand();
  const result = judge(playerHand, computerHand);
  console.log(`あなた：${playerHand}　vs　コンピュータ：${computerHand}`);
  console.log(`結果：${result}`);
  console.log("---");
}

// 動作確認
play("グー");
play("チョキ");
play("パー");
