//モジュール読み込み
const express = require('express');
const cors = require('cors');
const fs = require('fs');

//Expressアプリ作成
const app = express();

//CORS設定（フロントエンドからのアクセス設定）
app.use(cors());

//JSONファイル読み込み
const cpusData = JSON.parse(fs.readFileSync('./cpus.json', 'utf-8'));

