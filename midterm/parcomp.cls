\LoadClass[a4paper]{article}

\usepackage{fullpage}
\usepackage{fancyhdr}
\usepackage{amsmath}
\usepackage{color}
\usepackage{graphicx}
\usepackage{amssymb}
\usepackage{algorithm}
\usepackage{algpseudocode}
\usepackage{hyperref}
\usepackage{ulem}
\usepackage{tikz}
\usepackage{xparse}

\newcommand\head[2]{
    \rhead[\textsf{#1}]{\textsf{#1}}
    \lhead[\textsf{#2}]{\textsf{#2}}
}

\NewDocumentCommand\qkimgf{mmm}{
	\begin{figure}[h]
		\centering
		\includegraphics[width=#3\textwidth]{#1}
		\caption{#2}
	\end{figure}
}

\NewDocumentCommand\qkimg{mmg}{%
	\IfValueT{#3}{
		\qkimgf{#1}{#2}{#3}
	}
	\IfNoValueTF{#3}{
		\qkimgf{#1}{#2}{0.5}
	}
}

\cfoot[]{}
\rfoot[\thepage]{\textsf{\thepage}}
\renewcommand{\headheight}{14pt}
\renewcommand{\footrulewidth}{.4pt}
\renewcommand{\headsep}{25pt}
\renewcommand{\footskip}{25pt}

\newcommand\subtitle[1]{
    \paragraph{
        This is Parallel Computing with Kefu Lu.
		I am a student in the class.
		\textit{(insert generic collaboration policy)}
    }
	\paragraph{
		\textit{\textbf{On my honor, I have neither given nor recieved unauthorized aid on this #1.}}
	}\hfill\\
	Signed:\\
	\begin{center}
	\textit{Jack Bosco}\\
	\rule{5cm}{0.4pt}	
	\end{center}
}%

\newcommand{\red}[1]{%
	\textcolor{red}{#1}
}