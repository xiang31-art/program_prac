// ===== 簡易クイズアプリ =====

const quizzes = [
  { question: "JavaScriptの配列の要素数を取得するプロパティは？", answer: "length" },
  { question: "コンソールに出力する関数は？", answer: "console.log" },
  { question: "配列の末尾に要素を追加するメソッドは？", answer: "push" },
  { question: "小数点以下を切り捨てる関数は？", answer: "Math.floor" },
  { question: "JavaScriptで厳密に等しいか比較する演算子は？", answer: "===" }
];

function askQuestion(quiz, number) {
  console.log(`Q${number}: ${quiz.question}`);
  console.log(`あなたの回答：${quiz.answer}`);
}

function runQuiz() {
  let score = 0;

  for (let i = 0; i < quizzes.length; i++) {
    askQuestion(quizzes[i], i + 1);

    const correct = quizzes[i].answer;
    const userAnswer = correct; // 本来はユーザー入力だが、今回は正解を入れておく

    if (userAnswer === correct) {
      console.log("→ 正解！");
      score++;
    } else {
      console.log(`→ 不正解… 正解は「${correct}」`);
    }
    console.log("");
  }

  console.log("===== 結果 =====");
  console.log(`${quizzes.length}問中 ${score}問正解`);
  console.log(`正答率：${Math.floor(score / quizzes.length * 100)}%`);
}

// 動作確認
runQuiz();
