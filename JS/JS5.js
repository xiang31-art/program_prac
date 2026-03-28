// ===== 数当てゲーム =====

function generateAnswer(max) {
  return Math.floor(Math.random() * max) + 1;
}

function checkGuess(guess, answer) {
  if (guess === answer) {
    return "correct";
  }
  if (guess > answer) {
    return "high";
  }
  return "low";
}

function playGame(max, guesses) {
  const answer = generateAnswer(max);
  console.log(`1〜${max}の数を当ててください！`);
  console.log(`（挑戦回数：${guesses.length}回）`);
  console.log("");

  let attempts = 0;

  for (let i = 0; i < guesses.length; i++) {
    attempts++;
    const guess = guesses[i];
    const result = checkGuess(guess, answer);

    if (result === "correct") {
      console.log(`${guess} → 正解！ ${attempts}回目で当たりました！`);
      return;
    }
    if (result === "high") {
      console.log(`${guess} → もっと小さい数です。`);
    } else {
      console.log(`${guess} → もっと大きい数です。`);
    }
  }

  console.log(`残念…正解は ${answer} でした。`);
}

// 動作確認
playGame(10, [5, 3, 7, 8]);
console.log("---");
playGame(10, [2, 6, 4]);
