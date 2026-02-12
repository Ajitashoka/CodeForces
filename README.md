# 🚀 MCP Tool Automation Platform

A scalable **Microservices-based Automation Platform** designed to
enable intelligent repository understanding, document ingestion, vector
search, and graph-based reasoning using Agentic workflows.

------------------------------------------------------------------------

## 📌 Overview

The MCP Tool Automation Platform combines:

-   ⚙️ **FastAPI Gateway** (Orchestration Layer)
-   🤖 **Agent Service (LangGraph-based workflows)**
-   🐙 Git & Document Processing Services
-   🧠 Embedding + Vector Search (Qdrant)
-   📈 Graph Database (Neo4j)
-   💬 Angular Frontend (Chat Interface)

It enables semantic + relational querying across repositories and
documentation.

------------------------------------------------------------------------

# 🏗️ System Architecture

## 🔷 High-Level Architecture

``` mermaid
graph TB
    subgraph CLIENT["CLIENT LAYER"]
        UI["Angular Frontend"]
    end

    subgraph API["FASTAPI GATEWAY"]
        GW["API Gateway"]
    end

    subgraph CORE["CORE SERVICES"]
        AGENT["Agent Service"]
        GIT["Git Service"]
        UTIL["Utility Service"]
    end

    subgraph DATA["DATA SERVICES"]
        DOC["Document Service"]
        INGEST["Ingestion Service"]
        EMBED["Embedding Service"]
    end

    subgraph STORAGE["STORAGE LAYER"]
        QDRANT["Qdrant"]
        NEO4J["Neo4j"]
        LOGS["Logs"]
    end

    UI --> GW
    GW --> AGENT
    GW --> GIT
    GW --> UTIL
    GW --> DOC
    GW --> INGEST
    GW --> EMBED

    AGENT --> QDRANT
    AGENT --> NEO4J
    GIT --> INGEST
    DOC --> INGEST
    INGEST --> EMBED
    EMBED --> QDRANT
    INGEST --> NEO4J
```

------------------------------------------------------------------------

# 🔄 Data Processing Pipeline

``` mermaid
graph LR
    A["Input Repo/PDF"] --> B["Git / Doc Service"]
    B --> C["Ingestion"]
    C --> D["Embedding"]
    D --> E["Qdrant Vector DB"]
    C --> F["Neo4j Graph DB"]
    E --> G["Agent Service"]
    F --> G
    G --> H["User Chat Interface"]
```

------------------------------------------------------------------------

# 🔍 Query Flow

``` mermaid
graph TD
    U["User Query"] --> API["FastAPI Gateway"]
    API --> AG["Agent Service"]
    AG --> QD["Qdrant"]
    AG --> NJ["Neo4j"]
    QD --> AG
    NJ --> AG
    AG --> API
    API --> U
```

------------------------------------------------------------------------

# 🧠 Core Components

## 1️⃣ FastAPI Gateway

-   Central router
-   WebSocket + REST support
-   Authentication & orchestration

## 2️⃣ Agent Service

-   LangGraph-based workflow engine
-   Hybrid retrieval (Vector + Graph)
-   Context-aware response generation

## 3️⃣ Git Service

-   Clone / Pull repositories
-   Source code ingestion trigger

## 4️⃣ Document Service

-   Parse API guides / PDFs
-   Extract structured data

## 5️⃣ Ingestion Service

-   Clean & chunk data
-   Generate nodes & edges

## 6️⃣ Embedding Service

-   Generate vector embeddings
-   Store in Qdrant

## 7️⃣ Storage Layer

-   🔍 Qdrant → Semantic search
-   📈 Neo4j → Relationship reasoning
-   📋 Logs → Monitoring & observability

------------------------------------------------------------------------

# ⚙️ Tech Stack

-   **Backend:** FastAPI
-   **Frontend:** Angular
-   **Workflow Engine:** LangGraph
-   **Vector DB:** Qdrant
-   **Graph DB:** Neo4j
-   **Embedding Models:** OpenAI / Local LLM
-   **Containerization:** Docker (recommended)

------------------------------------------------------------------------

# 🚀 Key Features

✔ Microservices Architecture\
✔ Hybrid Retrieval (Vector + Graph)\
✔ Scalable & Modular Design\
✔ Real-time Chat via WebSockets\
✔ Repository + Document Intelligence\
✔ Observability & Logging

------------------------------------------------------------------------

# 📦 Future Enhancements

-   Kubernetes deployment
-   Role-based access control
-   Multi-tenant support
-   Advanced analytics dashboard
-   Streaming ingestion pipeline

------------------------------------------------------------------------

# 👨‍💻 Author

Designed for scalable AI-driven automation platforms.
