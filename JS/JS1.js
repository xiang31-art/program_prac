// ===== ToDoリスト（配列版） =====

const todos = [];

function addTodo(task) {
  todos.push(task);
  console.log(`「${task}」を追加しました。`);
}

function removeTodo(index) {
  if (index < 0 || index >= todos.length) {
    console.log("その番号のタスクは存在しません。");
    return;
  }
  const removed = todos.splice(index, 1);
  console.log(`「${removed[0]}」を削除しました。`);
}

function showTodos() {
  if (todos.length === 0) {
    console.log("タスクはありません。");
    return;
  }
  console.log("----- ToDoリスト -----");
  for (let i = 0; i < todos.length; i++) {
    console.log(`${i}: ${todos[i]}`);
  }
  console.log("----------------------");
}

// 動作確認
addTodo("買い物に行く");
addTodo("JavaScriptを勉強する");
addTodo("部屋を掃除する");
showTodos();

removeTodo(1);
showTodos();

addTodo("本を読む");
showTodos();
