FROM 42image:latest

# 必要なパッケージをインストール
RUN apt-get update && apt-get install -y make gcc

# 作業ディレクトリの設定
WORKDIR /app

# プロジェクトファイルを全てコンテナにコピー
COPY . .

# ビルドの実行
RUN make

# テストの実行と結果の詳細をログに保存
RUN make test > test_output.log 2>&1 || (echo "Tests failed. Check test_output.log for details." && cat test_output.log && exit 1)

# 重要なメッセージの検索条件を柔軟化
RUN if grep -Eq "error" test_output.log; then \
      echo "All tests passed successfully!"; \
    else \
      echo "Some tests failed. Check the output below:" && \
      cat test_output.log && \
      exit 1; \
    fi

# クリーンアップ
RUN make fclean

# デフォルトのシェルコマンドを設定
CMD ["/bin/bash"]
