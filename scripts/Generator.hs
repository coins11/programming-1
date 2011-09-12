
module Main where

import Data.List
import Control.Applicative
import Control.Monad

import System.Environment
import System.Process

main :: IO ()
main = do
    args <- getArgs
    case args of
        name : _ -> main' name
        _ -> return ()

latexsc :: IO () -> IO ()
latexsc action = do
    putStrLn $ "\\begin{shadebox}"
    putStrLn $ "\\begin{verbatim}"
    action
    putStrLn $ "\\end{verbatim}"
    putStrLn $ "\\end{shadebox}"

main' :: String -> IO ()
main' name = do
    putStrLn "\\subsection{ソースコード}"
    latexsc $ readFile (name ++ ".c") >>= putStr
    inputs <-
        zip [1..] <$> unfoldr phi <$> lines <$> readFile (name ++ ".input")
    forM_ inputs $ \(n, input) -> do
        putStrLn $ "\\subsection{実行例" ++ show n ++ "}"
        putStrLn "\\subsubsection{input}"
        latexsc $ putStr input
        putStrLn "\\subsubsection{output}"
        latexsc $ readProcess ("./" ++ name) [] input >>= putStr
    where
    phi :: [String] -> Maybe (String, [String])
    phi ls = case break (replicate 80 '-' ==) ls of
        (_, []) -> Nothing
        (l, _ : r) -> Just (unlines l, r)

