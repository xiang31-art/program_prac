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
        if (maker) params.append('maker', maker);
        if (grade) params.append('grade',grade)

        fetch(`http://localhost:3001/api/cpus/search?${params}`)
        .then(res => res.json())
        .then(data => setCpus(data));
    };

    // ソート処理
    const sortedCpus = [...cpus].sort((a, b) => {
        if (sortOrder === 'asc') return a.modelName.localeCompare(b.modelName);
        if (sortOrder === 'desc') return b.modelName.localeCompare(a.modelName);
        return 0;
    });

    return (
        <div className='app'>
            <h1>CPU検索アプリ</h1>

            <div className='search-area'>
                <input
                    type="text"
                    placeholder="キーワード検索"
                    value={keyword}
                    onChange={(e) => setKeyword(e.target.value)}
                    />

                    <select value={maker} onChange={(e) => setMaker(e.target.value)}>
                        <option value="">メーカー</option>
                        <option value="Intel">Intel</option>
                        <option value="AMD">AMD</option>
                    </select>

                    <select value={grade} onChange={e => setGrade(e.target.value)}>
                        <option value="">グレード</option>
                        <option value="i3">i3</option>
                        <option value="i5">i5</option>
                        <option value="i7">i7</option>
                        <option value="i9">i9</option>
                        <option value="Ryzen 3">Ryzen 3</option>
                        <option value="Ryzen 5">Ryzen 5</option>
                        <option value="Ryzen 7">Ryzen 7</option>

                    </select>

                    <select value={sortOrder} onChange={(e) => setSortOrder(e.target.value)}>
                        <option value="">ソート</option>
                        <option value="asc">型番 昇順</option>
                        <option value="desc">型番 降順</option>
                    </select>

                    <button onClick={handleSearch}>検索</button>
            </div>

            <div className="results">
                {sortedCpus.map(cpu => (
                    <div
                        key={cpu.id}
                        className="cpu-card"
                        onClick={() => setSelectedCpu(cpu)}
                    >
                        <span>{cpu.modelName}</span>
                        <span>{cpu.maker}</span>
                        <span>{cpu.grade}</span>
                    </div>
                ))}
            </div>

            {selectedCpu && (
                <div className="detail">
                    <h2>{selectedCpu.modelName}</h2>
                    <p>メーカー: {selectedCpu.maker}</p>
                    <p>グレード: {selectedCpu.grade}</p>
                    <p>世代: {selectedCpu.generation}</p>
                    <p>コア数: {selectedCpu.cores}</p>
                    <p>消費電力: {selectedCpu.power}W</p>
                    <p>Passmark: {selectedCpu.passmark}</p>
                </div>
            )}
        </div>
    );
}

export default App;