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

\newcommand\head[2]{
    \rhead[\textsf{#1}]{\textsf{#1}}
    \lhead[\textsf{#2}]{\textsf{#2}}
}

\cfoot[]{}
\rfoot[\thepage]{\textsf{\thepage}}
\renewcommand{\headheight}{14pt}
\renewcommand{\footrulewidth}{.4pt}
\renewcommand{\headsep}{25pt}
\renewcommand{\footskip}{25pt}

\newcommand\subtitle{
    \paragraph{
        This is Parallel Computing with Kefu Lu.
		I am a student in the class.
		\textit{(insert generic collaboration policy)}
    }
}