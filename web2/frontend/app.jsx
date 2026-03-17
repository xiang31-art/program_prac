import { useState, useEffect } from 'react';

function App() {
    // State定義
    const [cpus, setCpus] = useState([]);
    const [keyword ,setKeyword] = useState('');
    const [maker, setMaker] = useState('');
    const [grade, setGrade] = useState('');
    const [sortOrder, setSortOrder] = useState('');
    const [selectedCpu, setSelectedCpu] = useState(null);

    // 初回読み込み時に全件取得
    useEffect(() => {
        fetch('http://localhost:3001/api/cpus')
        .then(res => res.json())
        .then(data => setCpus(data));
    }, []);

    // 検索実行関数
    const handleSearch = () => {
        const params = new URLSearchParams();
        if (keyword) params.append('keyword', keyword);
        if (maker) params.append('grade', grade);

        fetch(`http://localhost:3001/api/cpus/serch?${params}`)
        .then(res => res.json())
        .then(data => setCpus(data));
    };

    // ソート処理
    const sortedCpus = [...cpus].sort((a, b) => {
        if (sortOrder === 'ask') return a.modelName.localCompare(b.modelName);
        if (sortOrder === 'desc') return b.modelName.localCompare(a.modelName);
        return 0;
    });

    return (
        <div>
            <h1>CPU検索アプリ</h1>
        </div>
    );
}

export default App;