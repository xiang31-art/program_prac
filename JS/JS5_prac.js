// === 数あてゲーム ===

function generateAnswer(max) {  //当てる数を生成する関数
    return Math.floor(Math.random() * max) + 1; //1~10の数を生成
}

function checkGuess(guess, answer) {    //ユーザーの回答が等しいか判定
    if (guess === answer) { //ユーザーの回答が正解である場合
        return "correct";   //等しいことを出力
    }
    if (guess > answer) {   //ユーザーの回答が大きい場合
        return "high";      //大きいことを出力
    }   //ユーザの回答が小さい場合(早期リターン)
        return "low";       //小さいことを出力
}

function playGame(max, guesses) {       //ゲームをする関数
    const answer = generateAnswer(max);    //正解の数を生成&保存
    console.log(`1〜${max}の数を当ててください!`);      //ゲームの説明
    console.log(` (挑戦回数：${guesses.length}回) `);   //回数の説明
    console.log("");        //改行

    let attempts = 0;       //挑戦回数カウント

    for (let i = 0; i < guesses.length; i++){   //挑戦回数までループ
        attempts++;                             //挑戦回数を1増やす
        const guess = guesses[i];               //プレイヤーが推測した配列の中身を取り出す
        const result = checkGuess(guess, answer);   //chechGuess関数により分かった結果を代入

        if (result === "correct"){                  //正しければ
            console.log(`${guess} → 正解! ${attempts}回目で当たりました!`); //結果表示
            return; //関数を終了
        }
        if (result ==="high") { //予測数字が大きかった時
            console.log(`${guess} → もっと小さい数です。`);
        } else {                //予測数字が小さかった時
            console.log(`${guess} → もっと大きい数です。`);
        }
    }
    console.log(`残念…正解は ${answer} でした。`);  //当てられなかった場合
}

//動作チェック
playGame(10, [5, 2, 7, 9]);
console.log("---");
playGame(20, [4, 16, 9, 12, 18]);