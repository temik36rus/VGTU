--
-- PostgreSQL database dump
--

-- Dumped from database version 15.4
-- Dumped by pg_dump version 15.4

-- Started on 2023-11-01 19:18:14

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 2 (class 3079 OID 16384)
-- Name: adminpack; Type: EXTENSION; Schema: -; Owner: -
--

CREATE EXTENSION IF NOT EXISTS adminpack WITH SCHEMA pg_catalog;


--
-- TOC entry 3347 (class 0 OID 0)
-- Dependencies: 2
-- Name: EXTENSION adminpack; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION adminpack IS 'administrative functions for PostgreSQL';


SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 216 (class 1259 OID 16399)
-- Name: Место; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Место" (
    id integer NOT NULL,
    "Название" character varying(100) NOT NULL,
    "Адрес" character varying(150) NOT NULL,
    "Наличие жилья участникам" character varying(10)
);


ALTER TABLE public."Место" OWNER TO postgres;

--
-- TOC entry 215 (class 1259 OID 16398)
-- Name: Место_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Место" ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Место_id_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    MAXVALUE 99999
    CACHE 1
);


--
-- TOC entry 218 (class 1259 OID 16405)
-- Name: Соревнование; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Соревнование" (
    id integer NOT NULL,
    "Дисциплина" character varying(100) NOT NULL,
    "Уровень" character varying(100) NOT NULL,
    "Организатор" character varying(100) NOT NULL,
    "Дата проведения" date NOT NULL,
    "Место_id" integer NOT NULL
);


ALTER TABLE public."Соревнование" OWNER TO postgres;

--
-- TOC entry 217 (class 1259 OID 16404)
-- Name: Соревнование_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Соревнование" ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Соревнование_id_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    MAXVALUE 99999
    CACHE 1
);


--
-- TOC entry 220 (class 1259 OID 16416)
-- Name: Тренер; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Тренер" (
    id integer NOT NULL,
    "ФИО" character varying NOT NULL,
    "Организация" character varying NOT NULL,
    "Стаж" integer,
    "Соревн_id" integer NOT NULL
);


ALTER TABLE public."Тренер" OWNER TO postgres;

--
-- TOC entry 219 (class 1259 OID 16415)
-- Name: Тренер_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Тренер" ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Тренер_id_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    MAXVALUE 99999
    CACHE 1
);


--
-- TOC entry 222 (class 1259 OID 16429)
-- Name: Участник; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Участник" (
    id integer NOT NULL,
    "ФИО" character varying(100) NOT NULL,
    "Пол" character varying(3) NOT NULL,
    "Возраст" integer NOT NULL,
    "Разряд" character varying(100),
    "Тренер_id" integer NOT NULL
);


ALTER TABLE public."Участник" OWNER TO postgres;

--
-- TOC entry 221 (class 1259 OID 16428)
-- Name: Участник_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Участник" ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Участник_id_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    MAXVALUE 99999
    CACHE 1
);


--
-- TOC entry 3190 (class 2606 OID 16403)
-- Name: Место Место_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Место"
    ADD CONSTRAINT "Место_pkey" PRIMARY KEY (id);


--
-- TOC entry 3192 (class 2606 OID 16409)
-- Name: Соревнование Соревнование_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Соревнование"
    ADD CONSTRAINT "Соревнование_pkey" PRIMARY KEY (id);


--
-- TOC entry 3194 (class 2606 OID 16422)
-- Name: Тренер Тренер_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Тренер"
    ADD CONSTRAINT "Тренер_pkey" PRIMARY KEY (id);


--
-- TOC entry 3196 (class 2606 OID 16433)
-- Name: Участник Участник_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Участник"
    ADD CONSTRAINT "Участник_pkey" PRIMARY KEY (id);


--
-- TOC entry 3197 (class 2606 OID 16410)
-- Name: Соревнование Место_id; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Соревнование"
    ADD CONSTRAINT "Место_id" FOREIGN KEY ("Место_id") REFERENCES public."Место"(id) ON DELETE CASCADE;


--
-- TOC entry 3198 (class 2606 OID 16423)
-- Name: Тренер Соревн_id; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Тренер"
    ADD CONSTRAINT "Соревн_id" FOREIGN KEY ("Соревн_id") REFERENCES public."Соревнование"(id) ON DELETE CASCADE;


--
-- TOC entry 3199 (class 2606 OID 16441)
-- Name: Участник Тренер_id; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Участник"
    ADD CONSTRAINT "Тренер_id" FOREIGN KEY ("Тренер_id") REFERENCES public."Тренер"(id) ON DELETE CASCADE NOT VALID;


-- Completed on 2023-11-01 19:18:15

--
-- PostgreSQL database dump complete
--

